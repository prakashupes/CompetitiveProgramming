#include<iostream>
using namespace std;
void print(int n)
{
	if(n<=0) return ;
	int num=n%10;
	print(n/10);
	
	if(num==0) cout<<" zero ";
	else if(num==1) cout<<" one ";
	else
	cout<<num<<" ";
}
int main()
{
	print(2016);

}
