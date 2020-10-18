#include<iostream>
using namespace std;

void sort(int *arr,int n)
{
	if(n==0 || n==1) return;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main()
{
	int arr[]={5,2,4,7,1,1,0,-1};
	
	sort(arr,8);
	cout<<"using bubble "<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	

}
