#include<iostream>
#include <queue>
#include "001_Tree.hpp"
#include "TreeData.hpp"

using namespace std;


using namespace MyTree;

int max(int a, int b)
{
	return a>b ? a:b ;

}
int maxOfTree(Node *root)
{
	if(root==NULL) return -1;
	
	return max(max (maxOfTree(root->left), maxOfTree (root->right)),root->key);
	
}

int main()
{
	Tree tree;
	cout<<maxOfTree(tree.root);
	
	

}
