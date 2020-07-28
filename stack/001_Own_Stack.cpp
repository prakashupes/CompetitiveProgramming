#include<iostream>
using namespace std;

template <class type2>
struct Node
{
	Node <type2> *next;
	type2 data;
	
	Node(type2 d)
	{
		data=d;
		next=NULL;
	}

};

template <class type>
class myStack
{
	Node <type> *head;
	public:
	void push(type data)
	{
		Node <type> *temp= new Node <type>(data);
		temp->next=head;
		head=temp;
	}
	
	void pop()
	{
		Node <type> *temp;
		temp=head;
		head=head->next;
		delete(temp);
	}
	
	type top()
	{
		return head->data;
	}


};
int main()
{
	myStack <string> s;
	s.push("hello");
	s.push("from");
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top();
	

}


