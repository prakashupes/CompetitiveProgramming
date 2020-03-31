#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node * next;
	
	Node (int data)
	{
		this->data=data;
		next=NULL;
		
	}

};
void insert(int data,Node ** headRef, Node ** tailRef)
{
	Node* temp=new Node(data);
	if(*headRef ==NULL)
		*headRef=temp;
	else
		(*tailRef)->next=temp;
	*tailRef=temp;
	
}
void printList(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ->";
		head=head->next;
	}

}

int main()
{
	Node* head=NULL;
	Node *tail=NULL;
	insert(1,&head,&tail);
	insert(2,&head,&tail);
	insert(3,&head,&tail);
	
	printList(head);
	
	

}
