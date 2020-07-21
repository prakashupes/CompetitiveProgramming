#include<iostream>
using namespace std;
  
string pad[6]= {"","","abc","def","ghi","jkl"}; //Same cahr pad[][6]= {"","","abc","def","ghi","jkl"};

void genrate(char *in, char *out,int i, int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<" ";
		return;
	}
	
	int digit=in[i]-'0';
	if(pad[digit]=="")
	{
		genrate(in,out,i+1,j);
	}
	
	for(int k=0;pad[digit][k]!='\0';k++)
	{
		out[j]=pad[digit][k];
		genrate(in,out,i+1,j+1);
		
	
	}
	return;
	

}

int main()
{
	char in [10];
	char out [10];
	cin>>in;
	genrate(in,out,0,0);
}
