#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int fun(int a,int b)
    {
        int dif=0;
        while((a!=0) && (b!=0)){
            if((a&1) != (b&1)) dif++;
            a=a>>1;
            b=b>>1;
        }
        while(b)
        {
            if(b&1) dif++;
            b=b>>1;
        }
        while(a)
        {
            if(a&1) dif++;
            a=a>>1;
        }
        
        return dif;
    }
    int countBits(int N, long long int A[])
    {
        // code here
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            for(int j=i;j<N;j++)
            {
                cout<<A[i]<<" "<<A[j]<<endl;
                //cout<<fun(A[i],A[j])<<endl;
            }
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
