#include<iostream>
#include<algorithm>
using namespace std;

bool large(char a, char b)
{
    return (a<b);
}
int main()
{
string s="cdaba";
int arr[]={1,2,3};
//cout<<*(s.end()-2)<<endl;
//cout<<arr[2];
sort(s.begin(),s.end());
cout<<"Sort in accending: "<<s<<endl;

sort(s.begin(),s.end(),greater<int>());
cout<<s<<endl;

//sort in perticula{6,8}, {1,9}r order
sort(s.begin(),s.end(),large);
cout<<s<<endl;

}

