#ifndef TREE_DATA
#define TREE_DATA
#include "001_Tree.hpp"
using namespace MyTree;
class Tree
{
	public:
	Node *root =new Node(5);
	
	Tree()
	{
		root->right= new Node(15);
		root->left= new Node (10);
		root->left->left =new Node(20);
		root->left->right =new Node(25);
		root->right->left =new Node(30);
	
	}

};

class TreeSet2 //Right skewed
{
	public:
	Node *root =new Node(5);
	
	TreeSet2()
	{
		root->right= new Node(10);
		root->right->left =new Node(15);
		root->right->left->right =new Node(25);
		
	}

};

class ChildrenSum //Right skewed
{
	public:
	Node *root =new Node(20);
	
	ChildrenSum()
	{
		root->right= new Node(15);
		root->left= new Node (5);
		root->left->left =new Node(2);
		root->left->right =new Node(3);
		//root->right->left =new Node(30);
		
	}

};

#endif
