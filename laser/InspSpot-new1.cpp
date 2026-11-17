#define API_EXPORT
#include "opencv2/opencv.hpp"
#include <algorithm>
//#include "log.h"
#include <time.h>
#include "InspSpot.h"

using namespace std;
using namespace cv;




#ifdef DEBUG_IMAGE_ALGORITHM
#pragma comment (lib, "opencv_calib3d310d.lib")
#pragma comment (lib, "opencv_core310d.lib")
#pragma comment (lib, "opencv_features2d310d.lib")
#pragma comment (lib, "opencv_flann310d.lib")
#pragma comment (lib, "opencv_highgui310d.lib")
#pragma comment (lib, "opencv_imgcodecs310d.lib")
#pragma comment (lib, "opencv_imgproc310d.lib")
#pragma comment (lib, "opencv_ml310d.lib")
#pragma comment (lib, "opencv_objdetect310d.lib")
#pragma comment (lib, "opencv_photo310d.lib")
#pragma comment (lib, "opencv_shape310d.lib")
#pragma comment (lib, "opencv_stitching310d.lib")
#pragma comment (lib, "opencv_superres310d.lib")
BOOL g_bDebugImageAlgorithm = TRUE;
#else
#pragma comment (lib, "opencv_calib3d310.lib")
#pragma comment (lib, "opencv_core310.lib")
#pragma comment (lib, "opencv_features2d310.lib")
#pragma comment (lib, "opencv_flann310.lib")
#pragma comment (lib, "opencv_highgui310.lib")
#pragma comment (lib, "opencv_imgcodecs310.lib")
#pragma comment (lib, "opencv_imgproc310.lib")
#pragma comment (lib, "opencv_ml310.lib")
#pragma comment (lib, "opencv_objdetect310.lib")
#pragma comment (lib, "opencv_photo310.lib")
#pragma comment (lib, "opencv_shape310.lib")
#pragma comment (lib, "opencv_stitching310.lib")
#pragma comment (lib, "opencv_superres310.lib")
#pragma comment (lib, "opencv_ts310.lib")
#pragma comment (lib, "opencv_video310.lib")
#pragma comment (lib, "opencv_videoio310.lib")
#pragma comment (lib, "opencv_videostab310.lib")
BOOL g_bDebugImageAlgorithm = FALSE;
#endif


// 是否在检测的原图上添加检测标记
BOOL g_bMarkInspImage = TRUE;


/// 默认的日志模块id
#define    MODULE_DEFAULT           1
#define    MODULE_SYSTEMINI         2
#define    MODULE_DB                3
#define    MODULE_CAMERA            4
#define    MODULE_DATA              5
#define    MODULE_WND               6
// 最多允许添加20个自定义日志模块
#define    MAX_MODULE_NUM           (MODULE_WND + 20)

//
void DEBUG_LOG(unsigned int nModleID, LPCTSTR pcsMessage)
{

}



int InspSot(unsigned char* data, int width, int height, double* speckle)
{
	char sDebug[512] = { 0 };
	if (!data || !speckle)
	{
		sprintf(sDebug, "输入的图片数据错误");
		DEBUG_LOG(MODULE_DATA, sDebug);
		return (int)INSP_UNKNOWN_ERROR;
	}

	speckle[0] = 0.0;
	speckle[1] = 0.0;

	Mat image(height, width, CV_8UC3, data);
	if (image.empty())
	{
		sprintf(sDebug, "图片加载失败");
		DEBUG_LOG(MODULE_DATA, sDebug);
		return (int)INSP_UNKNOWN_ERROR;
	}
	// 调试中读取本地文件上以BGR形式读取过来的，框架中缓冲区上RGB形式，需要做转换
//	if (!g_bDebugImageAlgorithm)
//	{
//		cvtColor(image, image, CV_RGB2BGR);
//	}

	/// 如果图像中只有1个亮斑很小的点，则取这个亮斑的中心返回
	Mat imageGray;
	cvtColor(image, imageGray, CV_BGR2GRAY);
	Mat imageBin;
	threshold(imageGray, imageBin, 150, 255, THRESH_BINARY);
	vector<vector<Point>> contours;
	vector<Vec4i> hireachy;
	Mat imageClone5 = imageBin.clone();
	findContours(imageClone5, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
	if (contours.size() == 0)
	{
		sprintf(sDebug, "轮廓个数1=%d", contours.size());
		DEBUG_LOG(MODULE_DATA, sDebug);
	}
	int nAreaNum = 0;
	int nBigAreaNum = 0;
	double dArea = 0.0;
	int nCountIndex = 0;

	for (size_t i = 0; i < contours.size(); i++)
	{
		dArea = contourArea(contours[i]);
		if (dArea > 0.0 && dArea < 1.0)
		{
			continue;
		}

		if (dArea > 5 && dArea < 90)
		{
			nCountIndex = i;
			nAreaNum++;
		}
		else
		{
			nBigAreaNum++;
		}
	}
	if (nBigAreaNum == 0 && nAreaNum == 1)
	{
		vector<Point> hullRegion2;
		convexHull(Mat(contours[nCountIndex]), hullRegion2, false);
		Moments moment;
		moment = moments(hullRegion2);
		Point2f ptLaserSpot;
		ptLaserSpot = Point2f(moment.m10 / moment.m00, moment.m01 / moment.m00);
		sprintf(sDebug, "激光斑中心坐标(%.2f, %.2f)", ptLaserSpot.x, ptLaserSpot.y);
		DEBUG_LOG(MODULE_DATA, sDebug);

		if (g_bMarkInspImage)
		{
			line(image, Point(ptLaserSpot.x - 10, ptLaserSpot.y - 10), Point(ptLaserSpot.x + 10, ptLaserSpot.y + 10), Scalar(0, 100, 0), 2);
			line(image, Point(ptLaserSpot.x + 10, ptLaserSpot.y - 10), Point(ptLaserSpot.x - 10, ptLaserSpot.y + 10), Scalar(0, 100, 0), 2);
		}

		if (g_bDebugImageAlgorithm)
		{
			imshow(SHOW_IMAGE_LINE_PTS, image);
		}

		speckle[0] = ptLaserSpot.x;
		speckle[1] = ptLaserSpot.y;

		return (int)INSP_OK;
	}

	Mat imageGauss;
	GaussianBlur(image, imageGauss, Size(3, 3), 0);

	if (g_bDebugImageAlgorithm)
	{
		imshow(SHOW_IMAGE_SRC, image);
	}

	/// 获得激光点坐标
	Mat hsv;
	cvtColor(imageGauss, hsv, COLOR_BGR2HSV);
	Mat imageBinLaserSpots1, imageBinLaserSpots2, imageBinLaserSpotsUnion;
	inRange(hsv, Scalar(0, 200, 46), Scalar(10, 255, 255), imageBinLaserSpots1);
	inRange(hsv, Scalar(0, 0, 200), Scalar(35, 150, 255), imageBinLaserSpots2);
	bitwise_or(imageBinLaserSpots1, imageBinLaserSpots2, imageBinLaserSpotsUnion);

	Mat outRegionsOpen, outRegionsClosing;
	Mat element1 = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
	morphologyEx(imageBinLaserSpotsUnion, outRegionsOpen, MORPH_OPEN, element1);
	Mat element2 = getStructuringElement(MORPH_ELLIPSE, Size(25, 25));
	morphologyEx(outRegionsOpen, outRegionsClosing, MORPH_DILATE, element2);

	int nAreaUnion = countNonZero(outRegionsClosing);
	if (nAreaUnion < 100)
	{
		DEBUG_LOG(MODULE_DATA, "获得光斑大致区域失败");
		return (int)INSP_FIND_IMAGE_ALL_ZERO_ERROR;
	}
	sprintf(sDebug, "光斑大致区域面积=%d", nAreaUnion);
	DEBUG_LOG(MODULE_DATA, sDebug);

	Mat imageSpotRegions;
// 	Mat hsvSpotRegions;
	imageGauss.copyTo(imageSpotRegions, outRegionsClosing);
// 	cvtColor(imageSpotRegions, hsvSpotRegions, COLOR_BGR2HSV);

	Mat imageChannel[3];
	split(imageSpotRegions, imageChannel);

	// 筛选出b(200-255) g(200-255)的区域
	Mat imageBSel;
	threshold(imageChannel[0], imageBSel, 200, 255, THRESH_BINARY);
	Mat imageGSel;
	threshold(imageChannel[1], imageGSel, 200, 255, THRESH_BINARY);

	Mat imageSelSpotsRegions;
	bitwise_or(imageBSel, imageGSel, imageSelSpotsRegions);

	Mat imageClone1 = imageSelSpotsRegions.clone();
	Mat imageLaserSpots = Mat::zeros(height, width, CV_8UC1);
	Mat imageShowLaserSpots = image.clone();
	findContours(imageClone1, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
	if (contours.size() == 0)
	{
		/// 光强度弱，图像中没有白色亮斑，求红色区域的中心作为结果
		DEBUG_LOG(MODULE_DATA, "没有白色亮斑的检测情况");
		Mat imageClone2 = outRegionsClosing.clone();
		findContours(imageClone2, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
		if (contours.size() == 0)
		{
			DEBUG_LOG(MODULE_DATA, "检测轮廓失败1");
			return INSP_FIND_IMAGE_ALL_ZERO_ERROR;
		}
		sprintf(sDebug, "轮廓个数1=%d", contours.size());
		DEBUG_LOG(MODULE_DATA, sDebug);
	}

	sprintf(sDebug, "轮廓个数2=%d", contours.size());
	DEBUG_LOG(MODULE_DATA, sDebug);

	/// 求不同区域的中心坐标，然后求这些中心坐标的中心距
	vector<Point> vecRegionHull;
	RNG rng(12345);
	Scalar color;
	for (size_t i = 0; i < contours.size(); i++)
	{
		dArea = contourArea(contours[i]);
		if (dArea < 1)
		{
			continue;
		}

		color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		if (g_bDebugImageAlgorithm)
		{
			drawContours(imageShowLaserSpots, contours, i, color, -1, 8, Mat(), 0, Point());
		}
		vecRegionHull.insert(vecRegionHull.end(), contours[i].begin(), contours[i].end());
	}

	if (vecRegionHull.size() == 0)
	{
		sprintf(sDebug, "激光斑凸包检测失败");
		DEBUG_LOG(MODULE_DATA, sDebug);
		return INSP_FIND_LASER_SPOT_CENTER_ERROR;
	}

	vector<Point> hullRegion2;
	convexHull(Mat(vecRegionHull), hullRegion2, false);
	Moments moment;
	moment = moments(hullRegion2);
	Point2f ptLaserSpot;
	ptLaserSpot = Point2f(moment.m10 / moment.m00, moment.m01 / moment.m00);
	sprintf(sDebug, "激光斑中心坐标(%.2f, %.2f)", ptLaserSpot.x, ptLaserSpot.y);
	DEBUG_LOG(MODULE_DATA, sDebug);

	if (g_bMarkInspImage)
	{
		line(image, Point(ptLaserSpot.x - 10, ptLaserSpot.y - 10), Point(ptLaserSpot.x + 10, ptLaserSpot.y + 10), Scalar(0, 100, 0), 2);
		line(image, Point(ptLaserSpot.x + 10, ptLaserSpot.y - 10), Point(ptLaserSpot.x - 10, ptLaserSpot.y + 10), Scalar(0, 100, 0), 2);
	}

	if (g_bDebugImageAlgorithm)
	{
		imshow(SHOW_IMAGE_LINE_PTS, image);
	}

	speckle[0] = ptLaserSpot.x;
	speckle[1] = ptLaserSpot.y;

	return (int)INSP_OK;
}
