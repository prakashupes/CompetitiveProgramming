#include<iostream>
using namespace std;

void swap(char &a,char &b)
{
    char t=a;
    a=b;
    b=t;
}

void printPer(string str,int i)
{
    if(i==str.length())
    {
        cout<<str<<" ";
        return;
    }

    for(int j=i;j<str.length();j++)
    {
        swap(str[i],str[j]);
        printPer(str,i+1);
        swap(str[j],str[i]);

    }
    return;

}

int main()
{
    string str="&*1#+";
    printPer(str,0);

}