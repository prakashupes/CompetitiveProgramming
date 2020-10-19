#include<iostream>
using namespace std;

void merge(int arr[],int s,int e)
{
	int temp[100];
	int i=s;
	int mid= (s+e)/2;
	int j=mid+1;
	int k=s;
	 while(i<=mid && j<=e)
	 {
	 	if(arr[i] < arr[j])
	 	{
	 		temp[k++]=arr[i++];
	 		//k++;
	 		//i++
	 	}
	 	
	 	else
	 	{
	 		temp[k++]=arr[j++];
	 	}
	 }
	 
	 while(i<=mid)
	 {
	 	temp[k++]=arr[i++];
	 }
	 
	 while(j<=e)
	 {
		 temp[k++]=arr[j++];
	 }
	 
	 for(i=s;i<=e;i++)
	 {
	 	arr[i]=temp[i];
	 }
	// cout<<endl;
	 

}

void mergesort(int *arr,int s,int e)
{
	if(s >= e) return;
	
	int mid= (s+e)/2;
	
	mergesort(arr,s,mid);
	mergesort(arr,mid+1,e);
	
	merge(arr,s,e);
		
	
	
}
int main()
{
	int arr[]={5,2,4,7,1,1,0,-1};
	
	mergesort(arr,0,7);
	cout<<"using Merge"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	

}
