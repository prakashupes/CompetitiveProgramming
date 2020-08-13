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


int main()
{
	BSTree tree;
	tree.genrateTree();
	cout<<floor(tree.root,16);


}
