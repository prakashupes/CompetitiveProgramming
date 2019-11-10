#include<iostream>
#include<algorithm>
using namespace std;
bool sortAss(string a,string b)
{
    return a<b;
}
int main()
{
    string arr[]={"xyz","abc","pqr"};
    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    sort(arr,arr+3,sortAssN);
    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }

}
