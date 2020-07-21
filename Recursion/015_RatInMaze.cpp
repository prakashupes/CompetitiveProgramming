#include<iostream>
using namespace std;
void printPath(char maze[][10], int path[][10],int i,int j)
//Here I am assumin 4*4
{
	if(i==3 && j==3)
	{
		//Solution founded
		path[i][j]=1;
		for(int p=0;p<4;p++)
		{
			for(int q=0;q<4;q++)
			{
				cout<<path[p][q]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	if(i>=4 || j>=4)
	{
		return;
	}
	if(maze[i][j]=='X')
	{
		return;
	}
	path[i][j]=1;
	printPath(maze,path,i,j+1);
	printPath(maze,path,i+1,j);
	path[i][j]=0;
	return;
	

}
int main()
{
  char maze[][10]={
  "0000",
  "00X0",
  "X00X",
  "0X00"
  
  };
  int path [10][10]={0};
  
  for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<maze[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
  
  printPath(maze,path,0,0);
  

}
