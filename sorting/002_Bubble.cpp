#include<iostream>
#include<vector>
using namespace std;

//Optimized in sorted array
template<class T>
void sort_2(vector<T> &a)
{
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		bool swapped=false;
		for(int j=i+1;j<n;j++){
			if(a[j-1]>a[j])
			{
				swap(a[j-1],a[j]);
				swapped=true;
			}
		}
		if(!swapped) break;
	}
}
void sort(int *arr,int n)
{
	if(n==0 || n==1) return;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
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
	cout<<endl;	
	//testing 2nd fun
	vector<int> v = {-1,0,22,3,4};
	sort_2(v);

	for(int i:v) cout<<i<<" ";
	cout<<endl;	

}
