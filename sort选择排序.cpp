//选择排序
//它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
#include <iostream>
using namespace std;
template <class T>
void sswap(T& x,T& y)
{
    T t;
    t=x;
    x=y;
    y=t;
}
template<class T>
void selectionsort(T a[],int n)
{
    
    for (int i = 0; i < n-1; i++)
    {
        int minnuber=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[minnuber]>a[j])
            {
                minnuber=j;
                sswap(a[i],a[minnuber]);
            }
        }
        
    }
    // cout<<'\n'<<endl;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<a[i]<<endl;
    }
    
}
int main()
{
    int n;
    cout<<"n="<<endl;
    cin>>n;
    int a[n];
    cout<<"请输入数组"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    selectionsort<int> (a, n);


}