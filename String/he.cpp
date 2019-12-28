#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
string s="cdaba";
int arr[]={1,2,3};
//cout<<*(s.end()-2)<<endl;
//cout<<arr[2];
sort(s.begin(),s.end());
cout<<"Sort in accending: "<<s<<endl;

sort(s.begin(),s.end(),greater<int>());
cout<<s;


}
