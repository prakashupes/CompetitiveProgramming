#include<iostream>
#include<string>

//Assumption small later
using namespace std;
int main()
{
    int arr[26]={0};

    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++)
    {
        arr[str[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        char ch=i+97;
        cout<<ch<<" :"<<arr[i]<<endl;

    }

}
