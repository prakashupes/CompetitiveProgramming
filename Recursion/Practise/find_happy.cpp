#include <iostream>
#include<unordered_set>
using namespace std;

bool find(int n,unordered_set <int> &s)
{
    if(n==1) return true;
    unordered_set<int> :: iterator itr; 
  
   
    if(s.find(n) != s.end())
    {
        return false;
    }
     s.insert(n);
    int sum=0;
    while(n>0)
    {
        sum+=(n%10)*(n%10);
        n=n/10;
    }
    //cout<<" sum "<<sum<<endl; 
   
    return find(sum,s);
}
int findHappy(int n)
{
    bool flag=false;
    unordered_set<int> s;
    while(!flag)
    {
        n++;
       // cout<<"n: "<<n<<endl;
       flag=find(n,s);
       s.clear();
        
    }
    return n;
}

int main() {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<findHappy(n)<<endl;
	    
	    
	}
	return 0;
}
