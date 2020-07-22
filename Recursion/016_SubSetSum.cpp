#include<iostream>
using namespace std;


void subsetSum(int *in, int *out, int i, int j,int size,int sum,int &count)
{
	if(i==size)
	{
		int temp_sum=0;
		out[j]=0;
		for(int k=0;k<=j;k++)
		{
			temp_sum+=out[k];
			//cout<<out[k];
			
		
		}
		//cout<<temp_sum<<" ";
		if(temp_sum==sum)
		{
			count++;
			for(int k=0;k<=j-1;k++){
			  
			cout<<out[k]<<", ";
			
		
			}
			cout<<endl;
		} 
		return;
	}
	out[j]=in[i];
	subsetSum(in,out,i+1,j+1,size,sum,count);
	subsetSum(in,out,i+1,j,size,sum,count);

}

int main()
{
	int arr[]={10,5,2,3,6};
	int arr2[10]={0};
	int size=sizeof(arr)/sizeof(arr[0]);
	//cout<<size;
	int count=0;
	subsetSum(arr,arr2,0,0,size,7,count);
	cout<<count<<" ";
	
}
