#include<iostream>
using namespace std;
void print(string str,string op,int i)
{
    if(i>=str.length())
    {
        cout<<op<<" ";
        return;
    }
    
    
    
    print(str,op,i+1);
    print(str,op+str[i],i+1);

}
int main()
{
    string str="ab";
    string op="";
    print(str,op,0);



}