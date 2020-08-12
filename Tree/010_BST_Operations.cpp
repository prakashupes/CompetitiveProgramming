#include<iostream>
#include "001_Tree.hpp"
#include <queue>
using namespace std;
using namespace MyTree;
void insert(Node **root,int k)
{
	if((*root)==NULL)
	{
		(*root)=new Node(k);
		return;
	} 
	
	if((*root)->key > k) insert(&(*root)->left,k);
	else insert(&(*root)->right, k);

}


Node* insert2(Node *root,int key)
{
	if(root==NULL)
	{
		root =new Node(key);
		return root;
	}
	if(root->key < key) root->right=insert2(root->right,key);
	else if(root->key > key) root->left=insert2(root->left,key);
	return root;

} 
void inOrder(Node *root)
{
	if(root == NULL) return;
	
	inOrder(root->left);
	cout<<root->key<<" ";
	inOrder(root->right);

}


void levelOerder(Node *root)
{
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1)
	{
		Node *temp=q.front();
		q.pop();
		if(temp==NULL)
		{
			cout<<endl;
			q.push(NULL);
			//q.pop();
			continue;
			
		
		}
		cout<<temp->key<<" ";
		if(temp->left!=NULL) q.push(temp->left);
		if(temp->right!=NULL) q.push(temp->right);
	
	}

}

int main()
{
	Node *root=NULL;
	
	insert(&root,10);
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,12);
	insert(&root,11);
	insert(&root,25);
	inOrder(root);
	cout<<endl;
	cout<<search(root,9)<<endl;
	cout<<search(root,10)<<endl;
	deleteNode(root,10);
	//inOrder(root);
	levelOerder(root);

}
