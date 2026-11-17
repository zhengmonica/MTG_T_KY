#ifndef __INSP_SPOT_H__
#define __INSP_SPOT_H__

#include <windows.h>


#ifdef API_EXPORT
#define INSP_API __declspec(dllexport)
#else
#define INSP_API __declspec(dllimport)
#endif




/// 检测返回结果定义
enum INSP_RET
{
	INSP_OK = 1,
	INSP_UNKNOWN_ERROR = -1,					// 输入图片问题、图片不清楚等错误
	INSP_FIND_IMAGE_ALL_ZERO_ERROR = -2,		// 图像是黑图
	INSP_FIND_LASER_SPOT_CENTER_ERROR = -3,		// 查找激光斑中心坐标失败

};


// 用于标记是否是调试算法的vs2013工程
extern BOOL g_bDebugImageAlgorithm;

#define SHOW_IMAGE_SRC			 "imagesrc"
#define SHOW_IMAGE_LINE_PTS      "imagepts"







/// 检测光斑点像素坐标
// 参数4：返回的检测结果，元素0、1分别是返回的像素坐标x，y
int InspSot(unsigned char* data, int width, int height, double* speckle);






#endif // __INSP_SPOT_H__
