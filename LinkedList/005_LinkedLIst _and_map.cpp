#include<iostream>
#include<map>
using namespace std;
struct Node
{
    int key;
    Node* next;
    Node(int key)
    {
        this->key=key;
        next=nullptr;
    }
};
//Insert begening
Node* insertAtBeg(int key,Node* head)
{
    Node* temp=new Node(key);
    temp->next=head;
    return temp;
}
//Insert at end

//This take O(n) bcz we have to traverse
Node* insertAtEnd(int key,Node* head)
{
    if(head==nullptr)
    {
        return new Node(key);
    }
    /*while(head->next!=nullptr)
        head=head->next;

    head->next=new Node(key);
    */
    Node *curr=head;
    while(curr->next!=nullptr)
        curr=curr->next;

    curr->next=new Node(key);
    return head;
}

Node* deleteEnd(Node * head)
{
    Node *curr=head;
    Node *prev=nullptr;
    while(curr->next!=nullptr)
    {
        prev=curr;
        curr=curr->next;

    }
    prev->next=nullptr;
    return head;

}

Node* deleteRandom(int key, Node* head)
{
    Node *curr=head;
    Node *prev=nullptr;
    while(curr->key!=key)
    {
        prev=curr;
        curr=curr->next;

    }
   prev->next=curr->next;
    return head;


}
Node * deleteBeg(Node* head)
{
    head=head->next;
    return head;

}
void display(Node* head)
{
    while(head!=nullptr)
    {
         cout<<head->key<<" head->next: "<<head->next<<" "<<head<<endl;
         head=head->next;
    }

}

void insertMap(Node* head,map<Node*,bool> &m)
{
	while(head!=nullptr)
    {
         m[head]=true;
         head=head->next;
    }

}

int main()
{
    Node *head=NULL;
    head=insertAtBeg(20,head);
    head=insertAtBeg(30,head);
    head=insertAtBeg(40,head);
    head=insertAtBeg(45,head);
    head=insertAtBeg(50,head);

    display(head);

    cout<<"\nPrint 2nd List\n";

    Node *head2=nullptr;
    head2=insertAtEnd(20,head2);
    insertAtEnd(30,head2);
    insertAtEnd(40,head2);
    insertAtEnd(50,head2);

    display(head2);

    cout<<"\nAfter delete Last head2(40,50)\n";
    deleteEnd(head2);
    deleteEnd(head2);
    display(head2);


    cout<<"\nDelete random key head(45)"<<endl;
    deleteRandom(45,head);
    display(head);

    cout<<"\n\nDelete beg head"<<endl;
    head=deleteBeg(head);
    display(head);
    
    cout<<"\nMap:\n";
    map<Node*,bool>m;
    insertMap(head,m);
    for(auto x:m)
    {
    	cout<<x.first<<" "<<x.second<<endl;
    }

}
