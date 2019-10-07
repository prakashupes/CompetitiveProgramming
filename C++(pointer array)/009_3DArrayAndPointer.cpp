#include<iostream>
using namespace std;
void pass(int (*arr)[2][3]) //int arr[][2][3]
{


}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int arr[2][2][3]=
        {
        {{1,2,3},{4,5,6} } ,
        { {7,8,9},{10,11,12}}
        };
    cout<<"1.Address\n";
    cout<<arr<<" "<<arr[0]<<" "<<arr[0][0]<<" "<<&arr[0][0][0]<<endl; //arr[0] == &arr[0]

    int (*p)[2][3]=arr; //now p ==arr

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout<<*(*(*(arr+i)+j)+k) <<" ";
            }
        }
    }
    cout<<endl;

    //Passing inside the function
    pass(arr);
    return 0;

}
