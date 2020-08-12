#include <iostream>
#include "BST.hpp"

int floor(Node *root,int k)
{
	if(root==NULL ) return -1;
	Node *res=NULL;
	
	while(root!=NULL)
	{
		if(root->key==k) return k;
		
		if(root->key > k) root=root -> left;
		else
		{
			res=root;
			root=root->right;
		
		}
	
	}
	if(res==NULL) return -1;
	return res->key;

}

Node *recFloor (Node *root, Node* prev, int k)
{
	if(prev==NULL && root ==NULL) return NULL;
	if(prev!=NULL && root ==NULL) return prev;
	if(root->key==k) return root;
	
	if(root->key > k) return recFloor(root->left,root->left,k);
	else return recFloor(root->right,root,k);

}

int main()
{
	BSTree tree;
	tree.genrateTree();
	//cout<<(tree.root)->key;
	Node *res =recFloor(tree.root,tree.root,1);
	if(res!=NULL)
	cout<<res->key<<" ";
	else cout<<"-1";


}
