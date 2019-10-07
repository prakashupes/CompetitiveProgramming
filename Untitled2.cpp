#include<iostream>
using namespace std;
int main()
{
    int siz;
    cin>>siz;
    int arr[siz];
    cout<<"Enter "<<endl;
    for(int i=0;i<siz;i++)
    {

        cin>>arr[i];

    }
     cout<<"Enter "<<endl;
    int q;
    cin>>q;
    while(q>0)
    {
        int n;
    cin>>n;
    int count=0;
    for(int i=0;i<siz;i++)
        {

            if(arr[i]==n)
                count++;
        }
        if(count==0)
            cout<<"Not present";
        else
            cout<<count;
        count=0;
        q--;


    }


}
