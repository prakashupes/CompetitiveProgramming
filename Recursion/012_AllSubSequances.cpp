#include<iostream>
using namespace std;




void print(string str,string op,int i) //Method 2
{
    if(i>=str.length())
    {
        cout<<op<<" ";
        return;
    }
    
    
    
    print(str,op,i+1);
    print(str,op+str[i],i+1);

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
	print(str2,op,0);
	

}
