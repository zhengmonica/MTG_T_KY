#ifndef CCIRCLEFIT_H
#define CCIRCLEFIT_H


#include <vector>
//#include "tunnelcal.h"
#include <map>
using namespace std;

struct CCircleData
{
    double x,y,z;
    double dp;  ///到平面的距离
    double dc;  ///到圆周的距离
    bool used;
};


class CCircleFit
{
    public:

        vector<CCircleData> data;   ///观测数据
        double center[3];          ///圆心坐标
        double radius;             ///半径
        double dplane;             ///平面度
        double dcircle;            ///圆度
        double normal[3];          ///盾构方法拟合的法向量
        double normal1[3];         ///法向量
        double ho,vo;///水平超前量和垂直超前量
        double fit;
        ///增加点数据
        bool AddData(double x,double y,double z,bool used =true);
        ///编辑
        bool ModifyData(int id,double x,double y,double z);
        ///移除
        bool RemoveData(int id);
        ///使用点数据
        bool UseData(int id,bool used);
        ///圆拟合
        bool Solv();
        CCircleFit();
        virtual ~CCircleFit();
    protected:
    private:
};

#endif // CCIRCLEFIT_H
