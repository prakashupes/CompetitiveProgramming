// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

bool sortNode(Node *n1,Node *n2)
{
    return n1->data < n2->data;
}

Node *flatten(Node *root)
{
   // Your code here
    Node *temp=root;
    vector<Node *>v;
    
    while(temp!=NULL)
    {
        v.push_back(temp);
        Node *temp2=temp->bottom;
        while(temp2!=NULL)
        {
            
            v.push_back(temp2);
            temp2=temp2->bottom;
        }
        temp=temp->next;
    }
    
    sort(v.begin(),v.end(),sortNode);
    
    Node *res=v[0];
    temp=res;
   // cout<<"res: "<<endl;
    cout<<"Printing vector \n";
    for(int i=1;i<v.size();i++)
    {
        temp->bottom=v[i];
        temp->next=NULL;
       // cout<<v[i]->data<<" ";
       // cout<<temp->data<<" ";
        temp=temp->bottom;
    }
    temp->next=NULL;
    Node *temp2=res;
    
    return res;

}


