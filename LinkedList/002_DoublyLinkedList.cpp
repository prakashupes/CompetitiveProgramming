#include<iostream>
using namespace std;

struct Node
{

    int key;
    Node* prev;
    Node* next;

    Node(int key)
    {
        this->key=key;
        next=prev=NULL;
    }


};

Node* insertBeg(int key,Node* head)
    {
        Node* temp=new Node(key);

        if(head==nullptr)
        {
            //head=temp;
            return temp;
        }


        temp->next=head;
        head->prev=temp;
        return temp;




    }

    Node* insertEnd(int key,Node* head)
    {
        if(head==nullptr)
        {
            return new Node(key);
        }
        Node* curr=head;
        Node* temp=new Node(key);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        temp->prev=curr;
        curr->next=temp;
        return head;



    }

    void display(Node* head)
    {


        while(head!=nullptr)
        {
            cout<<"Current "<<head->key<<" Prev "<<head->prev<<" Next "<<(head->next)<<endl;
            head=head->next;

        }

    }



int main()

{
    Node* head=nullptr;
    head=insertBeg(10,head);

    head=insertBeg(20,head);


    head=insertBeg(30,head);
    head=insertBeg(40,head);
    //head=insertBeg(50,head);

    display(head);

    Node* head2=NULL;
    head2=insertEnd(10,head2);
    insertEnd(20,head2);
    insertEnd(30,head2);
    insertEnd(40,head2);
    cout<<"\nHead2: \n";
    display(head2);

}
