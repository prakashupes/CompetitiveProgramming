#include<iostream>
using namespace std;
bool search(int *arr, int key,int n,int i)
{
	if(i==n) return false;
	
	if(arr[i]==key)return true;
	
	return search(arr,key,n,i+1);
}
int main()
{
 	int arr[4] ={1,2,3,-1};
 	if(search(arr,-6,4,0)) cout<<"Found ";
 	else cout<<"not found "<<endl;

}
