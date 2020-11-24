#include <iostream>
using namespace std;

int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else
        
        return (josephus(n - 1, k) + k-1) % n+1 ; /// n=1,2....n
        
        /*
        return fun(n-1,k)+k)%n;  n=0,1,2,3...
        */
} 
  
// Driver Program to test above function 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout <<josephus(n, k)<<endl; 
    }
   
    
    return 0; 
} 
