#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef pair < int , int > p;
#define rep(i,a,n)  for(int i = a; i < n; i++)
const int mod = 1000003;
const int N = 2e6+5;
int h[N] = {0}, sum[N] = {0};
 
int solve(vector<int> arr){
    int n=arr.size(), i, num;int ele = 0;
    int ans(0);
    
 
 	for(int i=0;i<n;i++)
 	{
 		 num=arr[i];
 		 h[num]++, sum[num]++;
 	}
    
    rep(i,1,N)sum[i] += sum[i-1];
    for(int i = 1; i < N; i++){
        if(h[i]){
        	ele = 0;
        	for(int j = i; j < N; j += i){
	            ans = (ans % mod + ((j / i) * 1LL * h[i] * h[j]) % mod) % mod;
	            if(i == j || i == 1)continue;
	           ans =(ans % mod + ( ((j-1) / i) * 1LL * (sum[j-1] - sum[j - i]) * (h[i])) % mod ) % mod;
			}
        }
        h[i] = 0;
        sum[i] = 0;
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        int x;
        cin>>x;
        vector<int> arr;
        for(int i=0;i<x;i++)
        {
        	int n;
        	cin>>n;
        	arr.push_back(n);
        }
        cout<<solve(arr);
 
    return 0;
}
