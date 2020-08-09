#include<iostream>
#include <queue>
#include "001_Tree.hpp"

using namespace std;


using namespace MyTree;

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
void levelOerder_M2(Node *root)
{
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		int s=q.size();
		
		for(int i=0;i<s;i++)
		{
			Node *temp=q.front();
			q.pop();
			cout<<temp->key<<" ";
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
		
		}
		
		cout<<endl;
	
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
	levelOerder(n);
	cout<<"\n"<<endl;
	levelOerder_M2(n);
	
	

}
