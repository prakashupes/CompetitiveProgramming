#include<iostream>
using namespace std;

int find_min(int *arr,int l,int h)
{
  int min=arr[l];
  int min_index=l;
  for(int i=l;i<h;i++)
  {
  	if(min>arr[i]) 
  	{
  	 min=arr[i]; 
  	 min_index=i;
  	}
  }
  
  return min_index;
}

void sort(int *arr,int n)
{
	if(n==0 || n==1) return;
	
	for(int i=0;i<n;i++)
	{
		int min= find_min(arr,i,n);
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;	
	}
	

}
int main()
{
	int arr[]={5,2,4,7,1,1,0};
	
	sort(arr,7);
	for(int i=0;i<7;i++)
	{
		cout<<arr[i]<<" ";
	}
	

}
