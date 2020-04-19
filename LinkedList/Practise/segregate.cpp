#include <iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node* next;
    
    Node (int k)
    {
        key=k;
        next=NULL;
    }
};

void insert(int key, Node **headRef, Node **tailRef)
{
    Node *temp=new Node(key);
    
    if(*headRef ==NULL)
        *headRef=temp;
    else
        (*tailRef)->next=temp;
    *tailRef=temp;
}

Node* Segregate(Node *head)
{
    Node *curr=head;
   
    Node *es=NULL;
    Node *os=NULL;
    Node *ee=NULL;
    Node *oe=NULL;
    while(curr!=NULL)
    {
        if((curr->key)%2==0)
        {
            if(es==NULL)
            {
                es=curr;
                ee=es;
            }
            else
            {
                ee->next=curr;
                ee=ee->next;
            }
        }
        else
        {
            if(os==NULL)
            {
                os=curr;
                oe=os;
            }
            else
            {
                oe->next=curr;
                oe=oe->next;
            }
        }
        curr=curr->next;
        
    }
    if(os==NULL || es ==NULL)
        return head;
    
    ee->next=os;
    oe->next=NULL;
    return es;
    
    
}
void display(Node *head)
{
    if(head==NULL)
        return;
    while(head!=NULL)
    {
        cout<<head->key<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	int n,key;

	while(t--)
	{
	    Node *head=NULL;
	    Node *tail=NULL;
	    cin>>n;
	    while(n--)
	    {
	        cin>>key;
	        insert(key,&head,&tail);
	    }
	    head=Segregate(head);
	    display(head);
	    
	    
	}
	return 0;
}
