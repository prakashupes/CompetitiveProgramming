#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    
	    int n,k,s,ans=0;
	    cin>>n>>k;
	    string str;
	    cin>>str;
	    
	    bool wall=false;
	    bool f=false;
	    for(int i=0;i<n;i++)
	    {
	        if(str[i]=='M')
	        {
	            //find iron
	            
	            int j=i;
	            while(j<n)
	            {
	                if(str[j]=='X')
	                {
	                    wall=true;
	                    break;
	                }
	                
	                if(str[i]==':')
	                {
	                    s++;
	                }
	                if(str[j]=='I')
	                {
	                    
	                    str[j]='P';
	                    f=true;
	                    break;
	                }
	                j++;
	            }
	            if(wall){
	                s=0;
	                wall=false;
	                i=j+1;
	               
	                
	            }
	            else if(f)
	            {
	                int p=k+1-s-abs(i-j);
	                if(p>0) ans++;
	                s=0;
	                i=j+1;
	                f=false;
	                
	            }
	            
	        }
	        
	        if(str[i]=='I')
	        {
	             int j=i;
	            while(j<n)
	            {
	                if(str[j]=='X')
	                {
	                    wall=true;
	                    break;
	                }
	                
	                if(str[i]==':')
	                {
	                    s++;
	                }
	                if(str[j]=='M')
	                {
	                    str[j]='P';
	                    break;
	                }
	                j++;
	            }
	            if(wall){
	                s=0;
	                wall=false;
	                i=j+1;
	                
	                
	            }
	            else if(f)
	            {
	                int p=k+1-s-abs(i-j);
	                if(p>0) ans++;
	                s=0;
	                i=j+1;
	                f=false;
	               
	                
	            }
	            
	        }
	        
	       
	    }
	    
	    
	    cout<<ans<<endl;
	}
	return 0;
}

