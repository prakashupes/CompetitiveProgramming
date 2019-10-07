#include<iostream>
using namespace std;
void oneD()
{
    int *arr =new int[5];/// Also a way of creating an array, int *arr =new int[5]
    for(int i=0;i<5;i++)
        arr[i]=i;
    for(int i=0;i<5;i++)
        cout<<sizeof(arr[i])<<"bytes ";
   // arr[6]=3;
    delete[] arr;
    cout<<" \n"<<arr[2];
}

void twoD()
{


    int*(*arr)= new int *[4];
    for(int i=0;i<4;i++)
    {
        //for(int j=0;j<5;j++)
            arr[i]=new int[5];  //4 cross 3
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
            arr[i][j]=i+j;  //4 cross 3
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
    }
    for(int i=0;i<4;i++)
        delete[] arr[i];

    delete[] arr;
}
int main()
{
    //twoD();
    oneD();
}
