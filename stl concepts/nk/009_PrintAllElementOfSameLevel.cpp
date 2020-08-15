#include<iostream>
#include <queue>
#include "001_Tree.hpp"
#include "TreeData.hpp"

using namespace std;

void printLevel(Node *root,int level)
{
	queue<Node *> q;
	q.push(root);
	int curr=1;
	
	while(!q.empty())
	{
		int s=q.size();
		for(int i=0;i<s;i++)
		{
			Node *temp = q.front();
			q.pop();
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
			
		
		}
		curr++;
		
		if(level==curr) break;
	
	}
	while(!q.empty()){
	cout<<q.front()->key<<" ";
	q.pop();
	}

}
int main()
{
	Tree tree;
	//leftView(tree.root);
	cout<<endl;
	TreeSet2 tree2;
	printLevel(tree.root,3);
	
	

}
