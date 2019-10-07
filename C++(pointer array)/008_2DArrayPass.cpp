#include<iostream>
using namespace std;
void traverse(int arr[][3]) //(int (*arr) [3]) or  int arr[][3]
{
    int (*p)[3]=arr;
    cout<<"Traversing in pass()\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*(*(p+i)+j)<<" "; // (*(p+i)+j) gives actual address where values are stored

        }
    }


}
int main()
{
    int arr[2][3]={ {1,2,3},{4,5,6}};
    traverse(arr);
}
