#include<iostream>
using namespace std;
//Stack using linked list

/*Approach:
if we use insert in last 1->2,->3
push(4);
we need to traverse 1->2->3->4.
same for pop()

if we make tail pointer:
1->2->3
push(4);
push at tail position: that will take O(1) 
but for pop();
it will again take o(n)

So approach 1:
make a dubly linked list:

Approach 2: Insert at head pointer:

1->2->3
push(4); 
for that
temp(4);
temp->next=head;
head=temp;

pop();
4->1->2->3;

temp=head;
head=head-next;
delete(temp);
*/



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

	bool isEmpty()
	{
		return (head==NULL);
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


