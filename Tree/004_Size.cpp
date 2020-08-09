#include<iostream>
#include <queue>
#include "001_Tree.hpp"
#include "TreeData.hpp"

using namespace std;


using namespace MyTree;

int sizeOfTree(Node *root)
{
	if(root==NULL) return 0;
	
	return sizeOfTree(root->left)+sizeOfTree(root->right)+1;
}

int main()
{
	Tree tree;
	cout<<sizeOfTree(tree.root);
	
	

}
