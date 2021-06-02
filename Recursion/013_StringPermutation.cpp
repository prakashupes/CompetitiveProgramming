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

//check if AB is not a substring
//M1 is check when printing that string is not containing AB as substr
//M2 using valid move

bool isValid(string str,int j,int i)
{
	
	cout<<"In "<<str<<endl;
	cout<<(i-1)<<str[i-1]<<" "<<j<<str[j]<<endl;
	if(i!=0 && str[i-1]=='A' && str[j]=='B')
	{
		
		return false;
	}
		
	return true;
}

void printPer2(string str, int i)
{
	if(i==str.size())
	{
		cout<<str<<" ";
	}
	for(int j=i;j<str.size();j++)
	{
		if(isValid(str,j,i))
		{
			swap(str[i],str[j]);
			printPer2(str,i+1);
			swap(str[i],str[j]);
		}
	}
}

int main()
{
	/*
	char a[100];
	//cout<<<<endl;
	cin>>a;	
	permut(a,0);
	*/
	string s="ABC";
	cout<<endl;
	printPer2(s,0);
	//swap (a[0],a[1]);
	//cout<<a;
}
