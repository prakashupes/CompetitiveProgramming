#include<iostream>
using namespace std;
//2^4
//Fast
int fastExp(int n)
{
    if(n==0)
        return 1;
    int ans=fastExp(n/2);
    if(n%2==0)
        return ans*ans;
    return 2*ans*ans;

}
int main()
{
    cout<<fastExp(5);
}
