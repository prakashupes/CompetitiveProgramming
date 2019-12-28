#include<iostream>
using namespace std;
int tiling(int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    return tiling(n-1)+tiling(n-4);

}
int main()
{
    int n;
    cout<<"Enter n";
     cin>>n;
     cout<<"Ways "<<tiling(n);

}
