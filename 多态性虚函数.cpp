//设计一个描述正方形的类square 并具有计算面积的成员函数 getarea（）
//从square中派生出矩形类rectangle rectangle也使用getarea（）函数计算面积
#include <iostream>
#include <math.h>
using namespace std;
class Square{
    public:
        //虚函数
        virtual double GetArea();
        Square(int edg);
        ~Square(){}
    protected:
        int edge;  //定义边长
};

//构造函数初始化
Square::Square(int edg){
    edge=edg;
}
double Square ::GetArea()
{
    double result;
    result=edge*edge;
    return result;
}
//下面的全剧函数是为了调用虚函数实现运行时的多态性而设计的
double objGetArea(Square *base);

class Rectang:public Square
{
    protected:
        int length;
    public:
        double GetArea();
         Rectang(int edg,int leng);
        ~Rectang(){}
};

double Rectang:: GetArea()
{
    double result;
    result=edge*length;
    return result;

}
Rectang::Rectang(int edg,int leng):Square(edg)
{
    //调用基类构造函数 Square（edg）使edge=edg；
    length=leng;
}
double objGetArea(Square* obj)
{
    return obj->GetArea();
}
int main()
{
    Square squal(100);//初始化
    class Rectang rect(200,300);
    cout<<"正方形面积为"<<squal.GetArea()<<endl;
     cout<<"正方形面积为"<<objGetArea(&squal)<<endl;
     cout<<"矩形的面积为"<<rect.GetArea()<<endl;
    return 0;

}
