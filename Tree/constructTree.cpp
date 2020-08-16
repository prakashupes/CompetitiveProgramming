#include <iostream>
#include "001_Tree.hpp"
using namespace std;
using namespace MyTree;
static int index=0;
Node* constructTree(int pre[], int in[], int s,int e)
{
	if(s>e) return NULL;
	
	Node *root = new Node(pre[index++]);
	//index++;
	if(s==e) return root;
	int find;
	for(int i=s;i<=e;i++){
		if(root->key==in[i]) find=i;
		
	}
	root->left=constructTree(pre,in,s,find-1);
	root->right=constructTree(pre,in,find+1,e);
	return root;

}

void inOrder(Node * root) //If we do modification then it will reflect on main also, but here we will only print
{
	if(root==NULL) return;	
	inOrder(root->left);
	cout<<root->key<<" ";
	inOrder(root->right);
	

}
int main()
{
	int in[]={35,30,40,25,50,45};
	int pre[]={25,30,35,40,45,50};
	
	
	Node *root=constructTree(pre,in,0,5);
	
	inOrder(root);

}

