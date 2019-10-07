#include<iostream>
using namespace std;
int main()
{

    int arr[2][3]={{1,2,3},{5,6,7} };
    cout<<&arr[0][0]<<" "<<&arr<<" "<<arr<<" "<<*arr<<endl;
    cout<<&arr[1][0]<<" "<<&arr[1]<<endl;
    //int *p=arr[0];
    //cout<<*p;
    cout<<*(*arr+1)<<endl;
    cout<<arr+1<<" "<<arr[1]<<" "<<*(arr+1)<<endl;
    cout<<*(*(arr+1))<<endl;
    //M1
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }

    //using a pointer refrance

    int (*p)[3]=arr;
    cout<<p<<" "<<*p<<" "<<p[0]<<endl; //p will work as arr
    for(int i=0;i<2;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<<*(*(p+i)+j)<<" ";
        }
        cout<<endl;
    }

    int m=(sizeof(arr)/sizeof(arr[0]));
    int n=(sizeof(arr[0])/sizeof(arr[0][0]));
    cout<<m<<endl;
    cout<<n;

}
