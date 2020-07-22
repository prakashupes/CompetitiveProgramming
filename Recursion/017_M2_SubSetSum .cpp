#include<iostream>
using namespace std;

int subsetSum(int arr[],int n,int sum)
{
	if(n==0)
	{
		return (sum==0)? 1: 0;
	}
	
	return subsetSum(arr,n-1,sum-arr[n-1]) +subsetSum(arr,n-1,sum);
}

int main()
{
	int arr[]={10,5,2,3,6};
	int arr2[10]={0};
	int size=sizeof(arr)/sizeof(arr[0]);
	//cout<<size;
	//int count=0;
	//subsetSum(arr,arr2,0,0,size,7,count);
	//cout<<count<<" ";
	cout<<subsetSum(arr,size,8);
}
