// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node * mergeResult(Node *head1,Node *head2)
{
    // your code goes here
    if(head1==NULL && head2==NULL) return NULL;
    Node *curr1=head1;
    Node *curr2=head2;
    Node *res=NULL;
      while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data <= curr2->data)
        {
            Node *temp=curr1->next;
        curr1->next=res;
        res=curr1;
        curr1=temp;
        }
       else
        {
           Node *temp=curr2->next;
        curr2->next=res;
        res=curr2;
        curr2=temp;
        }
    }
  
    
    while(curr1!=NULL)
    {
        Node *temp=curr1->next;
        curr1->next=res;
        res=curr1;
        curr1=temp;
    }
    while(curr2!=NULL)
    {
        Node *temp=curr2->next;
        curr2->next=res;
        res=curr2;
        curr2=temp;
    }
   
    return res;
    
}
