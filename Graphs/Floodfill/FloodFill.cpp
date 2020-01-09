#include<iostream>
using namespace std;

int R,C; //Figure dimentions
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void floodFill(char mat[10][30],char color,char prevColor,int src_x,int src_y)
{
//If matrix endes
    if(src_x<0 || src_y<0 || src_x>=R || src_y>=C)
        return;

    if(mat[src_x][src_y]!=prevColor)
        return;

        mat[src_x][src_y]=color;
    //For ech direction
    for(int k=0;k<4;k++)
    {
        floodFill(mat,color,prevColor,src_x+dx[k],src_y+dy[k]);
    }

}
int main()
{
     char matrix[10][30];
     cin>>R>>C;
     for(int i=0;i<R;i++)
     {
        for(int j=0;j<C;j++)
        {
            cin>>matrix[i][j];
        }
     }
     cout<<"Graph is"<<endl;
     for(int i=0;i<R;i++)
     {
        for(int j=0;j<C;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
     }
     floodFill(matrix,'*','.',5,10);
    // floodFill(matrix,'`','.',0,0);
     //For outside of region
     cout<<"Colored Graph:\n"<<endl;
     for(int i=0;i<R;i++)
     {
        for(int j=0;j<C;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
     }
}
