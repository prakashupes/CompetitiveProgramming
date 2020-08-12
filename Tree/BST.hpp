#ifndef BST
#define BST

#include "001_Tree.hpp"
using namespace MyTree;
class BSTree
{
	public:
	Node *root = NULL;
	 
	Node *root2 =NULL;
	
	Node* insertData(Node *root,int key)
	{
		if(root==NULL) return new Node(key);
		
		else if(root->key > key) root->left=insertData(root->left,key);
		else root->right =insertData(root->right,key);
		return root;
	
	}
	void genrateTree();
	


};

void BSTree::genrateTree()
{
		root=insertData(root,15);
		insertData(root,10);
		insertData(root,12);
		insertData(root,7);
		insertData(root,5);
		insertData(root,35);
		insertData(root,25);
		insertData(root,40);
		
		//2nd Tree
		root2=insertData(root2,25);
		root2=insertData(root2,15);
		root2=insertData(root2,10);
		root2=insertData(root2,12);
		root2=insertData(root2,35);
		root2=insertData(root2,30);
		root2=insertData(root2,40);
		root2=insertData(root2,37);
		root2=insertData(root2,45);
}
#endif
