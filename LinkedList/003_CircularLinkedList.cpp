#include<iostream>
using namespace std;

class Node
{
    public:
    int key;
    Node* next;

    Node(int key)
    {
        this->key=key;
        next=NULL;
    }

};

Node* insertBeg(int key,Node* head)
{
    Node* temp=new Node(key);
    if(head==nullptr)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=head;
    //Find last node

    Node* last=head;
    while(last->next!=head)
    {
        last=last->next;
    }
    last->next=temp;
    return temp;

}

void display(Node* head)
{
    Node* curr=head;
    do
    {
        cout<<curr->key<<" Curr Add: "<<curr<<" Next: "<<curr->next<<endl;
        curr=curr->next;
    }
    while(curr!=head);


}
int main()
{
    Node* head=nullptr;
    head=insertBeg(10,head);
    head=insertBeg(20,head);
    head=insertBeg(30,head);
    head=insertBeg(40,head);
    display(head);

    cout<<"\nStart printing from 30\n";
    display(head->next);


}
