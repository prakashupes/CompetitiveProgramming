#include<iostream>
using namespace std;

void sort(int *arr,int n)
{
	if(n==0 || n==1) return;
	for(int i=1;i<n;i++)
	{
		int hole=i;
		int val=arr[hole];
		while(hole>0 && val < arr[hole-1])
		{
			arr[hole]=arr[hole-1];
			hole--;
		
		}
		arr[hole]=val;
	}
}
int main()
{
	int arr[]={5,2,4,7,1,1,0,-1};
	
	sort(arr,8);
	cout<<"using Insertion "<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	

}
