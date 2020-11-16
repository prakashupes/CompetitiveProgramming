#include <iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 1299720
void seive(vector<int> &primes) 
{ 
	bool IsPrime[MAX_SIZE]; 
	for(int i=0;i<MAX_SIZE;i++)
	{
		IsPrime[i]=true;
	}
	
	for (int p = 2; p * p < MAX_SIZE; p++) 
	{ 
		if (IsPrime[p] == true) 
		{ 
			
			for (int i = p * p; i < MAX_SIZE; i += p) 
				IsPrime[i] = false; 
		} 
	} 
	for (int p = 2; p < MAX_SIZE; p++) 
	{
		if (IsPrime[p]) primes.push_back(p);
	}
	
			
}

int main() {
	// your code goes here
	
	std::vector<int> primes;
	seive(primes);
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int b[n];
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	    	cin>>b[i];
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        if(i==b[i-1])
	        {
	            a[i-1]=primes[i-1];
	        }
	       else a[i-1]=primes[n-1];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    
	    cout<<endl;
	    
	}
	
	
	return 0;
}

