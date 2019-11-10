#include<iostream>
#include<string>

//Find all digits from given string
//1abc 2abc
//o/p: 12
using namespace std;
int main()
{
 string str;
 getline(cin,str);

 string str2;
 for(int i=0;i<str.length();i++)
 {
    if(str.at(i)>='0' && str.at(i)<='9')
    {
        str2+=str.at(i);
    }
 }
 cout<<str2<<endl;
}
