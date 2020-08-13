#include <iostream>
using namespace std;
struct Abc
{
	int a;
	Abc(int i): a(i) {};

};
int main()
{
	Abc *p=new Abc(5);
	Abc **q=&p;
	
	cout<<p<<" "<<*q<<" ";
	cout<<p->a<<" "<<(*q)->a<<endl;
	(*q)->a=6;
	cout<<p->a<<" "<<(*q)->a<<" ";

}
