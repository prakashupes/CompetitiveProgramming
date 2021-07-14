// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void countandsort(long long arr[],long long l,long long h, long long &res, long long mid)
    {
        int local_res=0;
        int n1=(mid-l+1);
        int n2= h-mid;
        
        int a[n1],b[n2];
        
        for(int i=0;i<n1;i++)
        {
            a[i]=arr[l+i];
        }
        
        for(int j=0;j<n2;j++)
        {
            b[j]=arr[mid+j+1];
        }

        int i=0,j=0;
        int k=l;
        while(i<n1 && j<n2)
        {
            if(a[i]<=b[j]) {
                arr[k++]=a[i++];
            }
            else{
                arr[k++]=b[j++];
                local_res+=(n1-i);
            }
        }
        
        while(i<n1) arr[k++]=a[i++];;
        while(j<n2) arr[k++]=b[j++];
        
        //cout<<local_res<<endl;
        res+=local_res;
    }
    
    void countInver(long long arr[], long long l, long long h, long long &res)
    {
        if(l<h)
        {
            long long m=l+ (h-l)/2;
            countInver(arr,l,m,res);
            countInver(arr,m+1,h,res);
            countandsort(arr,l,h,res,m);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long res=0;
        long long l=0;
        countInver(arr,l,N,res);

        for(int i=0;i<N;i++)
        {
            cout<<arr[i]<<" ";
        }
        return res;
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0; 
}
  // } Driver Code Ends