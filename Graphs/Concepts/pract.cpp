#include<iostream>
using namespace std;
int main() {
    int n;
	cin>>n;
    int arr[n*2]={0};
    int arr2[n];
    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {

        cin>>arr2[i];
    }
    int j=0;
    for(int i=n;i<n*2;i++)
    {

        arr[i]=arr2[j];
        j++;
    }
    int m=0;
    for(int i=0;i<n*2;i++)
    {

        m=m+arr[i];
    }
    cout<<m/(n*2);

}
