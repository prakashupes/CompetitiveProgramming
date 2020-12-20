#include<iostream>
#include<stack>
using namespace std;

void leftSmaller(int arr[],int left[],int n)
{
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && s.top() > arr[i]) s.pop();
		
		if(s.empty()) left[i]=-1;
		else left[i]=s.top();
		
		s.push(arr[i]);
	
	}

}

void rightSmaller(int arr[],int right[],int n)
{
	stack<int>s;
	
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && s.top() > arr[i]) s.pop();
		if(s.empty()) right[i]=-1;
		else right[i]=s.top();
		
		s.push(arr[i]);
	
	}

}

int largestArea(int arr[],int n)
{
	if(n<1) return 0;
	int left[n],right[n];
	rightSmaller(arr,right,n);
	leftSmaller(arr,left,n);
	
	for(int i=0;i<n;i++)
	{
		
	}
	return -1;

}
int main()
{
	//int arr[]={2,4,6,7,3,9};
	//int arr[]={2,4,6,7,8,9};
	int arr[]={9,8,7,6,4,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	largestArea(arr,n);
	
	
	


}
