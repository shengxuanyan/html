//编写一个函数模板 实现两个变量交换
#include <iostream>
using namespace std;
template <class T>
void sswap(T& a,T& b)
{
    T t;
    t=a;
    a=b;
    b=t;
    cout<<"a="<<a<<"b="<<b<<endl;
}
int main()
{
    int a,b;
    cout<<"a="<<endl;
    cin>>a;
    cout<<"b="<<endl;
    cin>>b;
    sswap(a,b);
    return 0;
}
