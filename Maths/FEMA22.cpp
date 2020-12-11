#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	int n,k,s,ans=0;
	int p=0;
	while(t--)
	{
	    
	    
	    cin>>n>>k;
	    string str;
	    cin>>str;
	    
	    int i=0,j=0;
	    
	    while(i<n && j<n)
	    {
	        if(str[i]=='M')
	        {
	            
	            if(str[j]=='I')
	            {
	            	/*
	                if(i>j)
	                {
	                    while(i>j)
	                    {
	                        if(str[j]==':') s++;
	                        j++;
	                    }
	                }
	                else if(j>i)
	                {
	                    while(j>i)
	                    {
	                        if(str[i]==':') s++;
	                        i++;
	                    }
	                }
	                */
	                p=k+1-s-abs(i-j);
	                if(p>0) 
	                {
	                    ans++;
	                    s=0;
	                }
	                
	                
	            }
	            else if(str[j]=='X')
	            {
	                i=j+1;
	                j++;
	                s=0;
	            }
	            else j++;
	        }
	        if(str[i]=='X')
	        {
	            
	            j=i ;
	            i++;
	        }
	        else i++;
	        
	    }
	    
	    
	    cout<<ans<<endl;
	    ans=0;
	}
	return 0;
}

