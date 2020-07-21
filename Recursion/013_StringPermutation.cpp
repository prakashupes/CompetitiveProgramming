#include<iostream>
using namespace std;

void swap(char &a, char &b)
{
	char temp;
	temp=a;
	a=b;
	b=temp;
	return;
}
void permut(char *a, int i)
{
	if(a[i]=='\0')
	{
		cout<<a<<" ";
		return;
	}
	/*
	if(a[i]=='\0' || a[j]=='\0')
	{
		cout<<a<<" ";
		return;
	}
	swap(a[i],a[j]);
	permut(a,i+1,j+1);
	permut(a,i,j+1);
	*/
	for(int j=i; a[j]!='\0';j++)
	{
		swap(a[i],a[j]);
		permut(a,i+1);
		swap(a[i],a[j]);
	}
	
	

}
int main()
{
	char a[100];
	//cout<<<<endl;
	cin>>a;	
	permut(a,0);
	//swap (a[0],a[1]);
	//cout<<a;
}
