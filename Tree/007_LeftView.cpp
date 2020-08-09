#include<iostream>
#include <queue>
#include "001_Tree.hpp"
#include "TreeData.hpp"

using namespace std;


using namespace MyTree;

int maxLevel = 0;
void leftView(Node *root,int level=1)
{
	if(root==NULL) return;
	if(level>maxLevel)
	{
		cout<<root->key<<" ";
		maxLevel=level;
	}
	leftView(root->right,level+1);
	leftView(root->left,level+1);
	

}
int main()
{
	Tree tree;
	//leftView(tree.root);
	cout<<endl;
	TreeSet2 tree2;
	leftView(tree2.root);
	
	

}
