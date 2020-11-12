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


bool search(Node *root, int key)
{
	if(root==NULL) return false;
	
	if(root->key == key) return true;
	
	if(root->key > key) return search(root->left,key);
	else return search(root->right,key);
	

}

int findSuccessor(Node *root)
{
	Node *curr=root->right;
	while(curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr->key;

}

Node* findDecendants (Node * root)
{
	root =root->left;
	while(root->right!=NULL) root= root->right;
	return root;

}
Node *deleteNode(Node *root,int k)
{
	if(root==NULL) return NULL;
	
	if(root->key >k)
	{
		root->left = deleteNode (root->left,k);
	}
	else if(root->key < k) root->right = deleteNode (root->right,k);
	else if(root->key == k)
	{
		if(root->left == NULL)
		{
			Node *temp =root->right;
			delete root;
			return temp;
		}
		
		if(root->right == NULL)
		{
			Node *temp =root->left;
			delete root;
			return temp;
		}
		
		else
		{
			
			Node * temp = findDecendants(root);
			
			/***M2
			int k= findSuccessor(root);
			root->key=k;
			****/
			
			root->key = temp->key;
			deleteNode(root->left,temp->key);
			
			
		
		}
		
	
	}
	return root;

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
	//cout<<search(root,9)<<endl;
	//cout<<search(root,10)<<endl;
	deleteNode(root,10);
	inOrder(root);
	//levelOerder(root);

}
