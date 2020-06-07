#include<iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n>0)
        {
            if(n==0) return 1;
            return x*myPow(x,n-1);
        }
        else
        {
            if(n==0) return 1;
            return (1/x)*(myPow(x,n+1));
        }
            
        
    }
};

int main(int argc, char *argv[])
{
    int n;
    double x;
    cin>>x;
    cin>>n;
    Solution s;
    cout<<s.myPow(x,n);
}

