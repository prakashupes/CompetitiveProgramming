#include<iostream>
#include "001_Tree.hpp"
using namespace std;
using namespace MyTree;
Node * insert2(Node *root,int k)
{
	if((root)==NULL)
	{
		return new Node(k);
	} 
	
	Node *curr=root;
	Node * prev =curr;
	while(curr!=NULL)
	{
		prev=curr;
		if(curr->key > k)
		curr=curr->left;
		
		else if(curr->key < k)
		curr=curr->right;
	
	}
	if(prev->key > k) prev->left = new Node (k);
	else prev->right = new Node (k);
	return root;

}


void inOrder(Node *root)
{
	if(root == NULL) return;
	
	inOrder(root->left);
	cout<<root->key<<" ";
	inOrder(root->right);

}


int main()
{
	
	Node *root2=NULL;
	root2=insert2(root2,10);
	root2=insert2(root2,5);
	insert2(root2,4);
	insert2(root2,1);
	insert2(root2,0);
	insert2(root2,12);
	inOrder(root2);


}
