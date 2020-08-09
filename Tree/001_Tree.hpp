#ifndef TREE_STRUCTURE
#define TREE_STRUCTURE
#include<iostream>
using namespace std;
namespace MyTree
{
	struct Node
{
	Node *left;
	Node *right;
	int key;
	Node(int k) : key(k)
	{
		
		left=NULL;
		right=NULL;
	}
};


}


#endif //  TREE_STRUCTURE

