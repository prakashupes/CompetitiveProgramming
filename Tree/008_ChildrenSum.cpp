#include<iostream>
#include <queue>
#include "001_Tree.hpp"
#include "TreeData.hpp"

using namespace std;


using namespace MyTree;

bool childrenSum(Node *root)
{
	if(root==NULL) return true;
	
	int sum=0;
	if(root->left!=NULL) sum+= root->left->key;
	if(root->right != NULL) sum+= root->right->key;
	
	return (sum==root->key && root->left && root->right); 

}

int main()
{
	ChildrenSum tree;
	cout<<childrenSum(tree.root);
	
	

}
