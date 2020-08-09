#include<iostream>
#include <queue>
#include "001_Tree.hpp"
#include "TreeData.hpp"

using namespace std;


using namespace MyTree;

void kth(Node *root, int k)
{
	if(root==NULL) return;
	if(k==0) cout<<root->key<<" ";
	kth(root->left,k-1);
	kth(root->right,k-1);

}

//M2

void kth_M2(Node *root, int k, int visited_level=0)
{
	if(root==NULL) return;
	if(k==visited_level) cout<<root->key<<" ";
	kth_M2(root->left,k,visited_level+1);
	kth_M2(root->right,k,visited_level+1);
	

}
int main()
{
	Tree tree;
	kth_M2(tree.root,2);
	
	

}
