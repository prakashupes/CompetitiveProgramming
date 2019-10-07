#include<iostream>
using namespace std;

int totalWays(int n)
{
    if(n==0)
        return 0;
    if(n==1||n==2)
        return n;
    return totalWays(n-1)+totalWays(n-2);
}
int main()
{
    int n=4;
    cout<<totalWays(n);
}
