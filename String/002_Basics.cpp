#include<iostream>
using namespace std;

void method1()
{

    //Method 1
    //But we cannt modify the string
    //Cannt take input
    char* str1="HEllo world";
    cout<<str1<<"\n";
    char* str2;
}
void method2()
{
 //M2
   string str="HEllo world";
   cout<<str<<endl;
   cout<<str[12]<<endl;
    str[2]='p';
   string str2;
   cin>>str2;
   cout<<str2<<endl;
   str2=str2+str;
   cout<<str2;
}
int main()
{

    //method1();
     method2();

}
