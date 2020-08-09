#include<iostream>
#include <queue>
#include "001_Tree.hpp"

using namespace std;


using namespace MyTree;

void inOrder(Node * root) //If we do modification then it will reflect on main also, but here we will only print
{
	if(root==NULL) return;
	
	inOrder(root->left);
	cout<<root->key<<" ";
	inOrder(root->right);
	

}
void preOrder(Node * root) //If we do modification then it will reflect on main also, but here we will only print
{
	if(root==NULL) return;
	cout<<root->key<<" ";
	inOrder(root->left);
	
	inOrder(root->right);
	

}
void postOrder(Node * root) //If we do modification then it will reflect on main also, but here we will only print
{
	if(root==NULL) return;
	
	inOrder(root->left);
	
	inOrder(root->right);
	cout<<root->key<<" ";

}

void levelOerder(Node *root)
{
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node * temp=q.front();
		cout<<temp->key<<" ";
		
		q.pop();
		if(temp->left!=NULL)q.push(temp->left);
		
		if(temp->right!=NULL)q.push(temp->right);
	
	}

}
int main()
{
	MyTree:: Node *n=new MyTree::Node(5); //root is 5
	
	n->right= new Node(15);
	n->left= new Node (10);
	n->left->left =new Node(20);
	n->left->right =new Node(25);
	n->right->left =new Node(30);
	inOrder(n);
	cout<<endl;
	preOrder(n);
	cout<<endl;
	postOrder(n);
	cout<<endl;
	levelOerder(n);
	
	

}
