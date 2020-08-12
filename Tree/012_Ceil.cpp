#include <iostream>
#include "BST.hpp"

int ceil(Node *root,int k)
{
	Node * res =NULL;
	
	while(root!=NULL)
	{
		if(root->key==k)return k;
		if(root->key > k)
		{
			res=root;
			root=root->left;
		}
		
		else if(root->key < k)
		{
			root = root ->right;
		
		}
	
	}
	if(res==NULL) return -1;
	return res->key;
	

}


int main()
{
	BSTree tree;
	tree.genrateTree();
	
	cout<<ceil(tree.root2,4);


}
