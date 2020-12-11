#include<iostream>
#include<string.h>
using namespace std;
int main()
{

    string s="hacker";
    
    int n=s.length();
    string shifted="";
    int k=3;
    for(int i=0;i<s.length();i++)
    {
        int index=(i+k)%n;
        shifted+=s[index];
    }
    
        cout<<shifted;
    
    





}
