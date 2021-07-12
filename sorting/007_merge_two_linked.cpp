//Merge two sorted linked list
#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int a)
    {
        val=a;
        next=NULL;
    }
};

//push into node
//1->null

Node* insert(Node *head,int val)
{
   // cout<<&head<<" ";
    Node *ref=head;
    Node *temp=new Node(val);
    if(head==NULL)
    {
        head=temp;
        return head;
    }

    while(ref->next!=NULL)
    {
        ref=ref->next;
    }
    ref->next=temp;
    return head;
    
}

void print(Node *head)
{
    Node *ref=head;
    while(ref!=NULL)
    {
        cout<<ref->val<<" ";
        ref=ref->next;

    }
}


//mERGE 

Node* merge(Node *h1, Node* h2)
{
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;

    Node *res= NULL;
    Node *end=NULL; //Keep track of end of linked list that needs to be return

    if(h1->val < h2->val)
    {
        res=end=h1;
        h1=h1->next;
    }
    else if(h1->val > h2->val)
    {
        res=end=h2;
        h2=h2->next;
    }

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->val < h2->val)
        {
            end->next=h1;
            end=end->next;
            h1=h1->next;
        }
        else if (h1->val >= h2->val)
        {
            end->next=h2;
            end=end->next;
            h2=h2->next;
        }
    }

    return res;

}

int main()
{
    Node *head=NULL;

   // cout<<&head<<" ";
    head=insert(head,1);
    insert(head,3);
    insert(head,5);
    insert(head,9);
    /*
    :From the next time we do not write head=insert(head,1); becz the address of Node *head of insert also remain same, 
    and once we have assigned head=insert(head,1); then it always point to this.
    */
   
   // cout<<&head<<" ";

   Node *head2=NULL;
   head2=insert(head2,2);
    insert(head2,6);
     insert(head2,8);
      insert(head2,10);
    insert(head2,11);
    

    Node *res= merge(head,head2);
    
    print(res);
    cout<<endl;
}