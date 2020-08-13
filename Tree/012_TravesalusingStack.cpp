#include <iostream>
#include "BST.hpp"
#include <stack>

using namespace std;
void inOrder(Node *root)
{
	stack<Node*> s;
	s.push(root);
	Node* curr=root->left;
	
	while(!s.empty() || curr!=NULL )
	{
		
		if(curr!=NULL)
		{
			s.push(curr);
			curr= curr->left;
		
		}
		else
		{
			curr=s.top();
			s.pop();
			cout<<curr->key<<" ";
			curr=curr->right;
			
		
		}
		
	}

}


void preOrder(Node *root)
{
	stack<Node*> s;
	s.push(root);
	Node* curr=root->left;
	cout<<root->key<<" ";
	while(!s.empty() || curr!=NULL)
	{
		
		if(curr!=NULL )
		{
			
			s.push(curr);
			cout<<(s.top())->key<<" ";
			curr= curr->left;
		
		}
		else
		{
			curr=s.top();
			s.pop();
			
			curr=curr->right;
			
		
		}
		
	}

}

void postOrder(Node *root)
{
	stack<Node*> s;
	s.push(root);
	Node* curr=root->left;
	while(!s.empty() || curr!=NULL)
	{
		
		if(curr!=NULL )
		{
			
			s.push(curr);
			curr= curr->left;
		
		}
		else
		{
			curr=s.top();
			curr=curr->right;
			
			if(curr==NULL)
			{
				cout<<(s.top())->key<<" ";
				s.pop();
			}
			
		
		}
		
	}

}



int main()
{
	BSTree tree;
	tree.genrateTree();
	inOrder(tree.root);
	cout<<endl;
	preOrder(tree.root);
	cout<<endl;
	//postOrder(tree.root);



}
