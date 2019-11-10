#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string str1="300",str2="45.3";

    //Converting string to int
    int a=stoi(str1);
    cout<<a+1<<endl;

    //Converting string to int
    float f=stof(str2);
    cout<<f+1<<endl;

    //Converting int to string

    string str3=to_string(a);
    str3+=to_string(f);
    cout<<str3;



}
