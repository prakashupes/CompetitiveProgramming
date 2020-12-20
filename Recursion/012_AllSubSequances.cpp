#include<iostream>
using namespace std;


void substrings_m2(string str,string op)
{
	if(str.length()==0)
	{
		cout<<op<<" ";
		return;
	}
	substrings_m2(str.substr(1),op);
	
	substrings_m2(str.substr(1),op+str[0]);

}

void substrings(char* str,int i,int j,char* output,int *count)
{
	if(str[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<", ";
		(*count)++;
		return;
	}
	output[j]=str[i];
	
	substrings(str,i+1,j+1,output,count);
	substrings(str,i+1,j,output,count);

}
int main()
{
	char str[100];
	
	char output[100];
	int count=0;
	cin>>str;
	substrings(str,0,0,output,&count);
	cout<<"Total "<<count;
	cout<<endl;
	string str2="abc";
	string op="";
	substrings_m2(str2,op);
	

}
