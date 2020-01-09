#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    cout<<"Pattern\n\n\n";
    //First Component
    cout<<"*";
    for(int i=1;i<=(n-3)/2;i++)
    {
        cout<<" ";
    }
    for(int i=1;i<=(n+1)/2;i++)
    {
        cout<<"*";
    }

    cout<<endl;

    //2 Component
    for(int i=2;i<(n+1)/2;i++)
    {
        cout<<"*";
        for(int j=1;j<=(n-3)/2;j++)
        {
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }

    //First Component
    for(int i=1;i<=n;i++)
    {
        cout<<"*";
    }
    cout<<endl;

    //First Component

    for(int i=((n+1)/2)+1;i<n;i++)
    {
        for(int j=1;j<=((n-3)/2)+1;j++)
        {
            cout<<" ";
        }
        cout<<"*";

        for(int j=1;j<=(n-3)/2;j++)
        {
            cout<<" ";
        }
        cout<<"*"<<endl;

    }

    //First Component
    for(int i=1;i<=(n+1)/2;i++)
    {
        cout<<"*";
    }
    for(int i=1;i<=(n-3)/2;i++)
    {
        cout<<" ";
    }
    cout<<"*";
    cout<<"\n\n"<<endl;


}
