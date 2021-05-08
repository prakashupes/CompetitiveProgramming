// C++ program for Boggle game
#include <bits/stdc++.h>
using namespace std;

// Converts key current character into index
// use only 'A' through 'Z'
#define char_int(c) ((int)c - (int)'A')

// Alphabet size
#define SIZE (26)

#define M 4
#define N 4
const vector<int> row_offset = { -1, -1, -1, 0, 1, 0, 1, 1 };
const vector<int> col_offset =  { -1, 1, 0, -1, -1, 1, 0, 1 };

typedef struct TrieNode
{
    TrieNode *Child[26];
   bool isEnd;

   TrieNode()
   {
       isEnd=false;
       for(int i=0;i<26;i++)
       {
           Child[i]=NULL;
       }
   }
    
} TrieNode;

void insert(TrieNode *root, string word)
{
    TrieNode *ref=root;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(ref->Child[index]==NULL)
        {
            ref->Child[index]=new TrieNode();
        }
        ref=ref->Child[index];
    }
    ref->isEnd=true;
}

bool search(TrieNode *root, string word)
{
    TrieNode *ref=root;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(ref->Child[index]==NULL)
        {
            return false;
        }
        ref=ref->Child[index];
    }
    return true; //not more relialable ... (read next line)
    //return (ref!=NULL && ref->isEnd); //Or if you want to search substring also then remove ref->end condition
}

// function to check that current location
// (i and j) is in matrix range

// A recursive function to print all words present on boggle

    void backtracking(int row, int col, vector<vector<char>> board, vector<string>& ret, TrieNode* root, const string& prefix){
        if(root->isEnd){
            ret.push_back(prefix);
            root->isEnd = false; //do not want to duplicate the word
        }
        char letter = board[row][col]; // purely for backtracking 
        board[row][col] = '$';
        //cout<< prefix << endl;
        for(int d = 0; d < 8; d++){
            int nr = row + row_offset[d]; // new cell to explore - neighbor
            int nc = col + col_offset[d];  
            if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4 )  continue;
            if(board[nr][nc] == '$') continue;
            if(board[nr][nc]=='*')
            {
               for(int k=0;k<26;k++)
                    {
                        char c='a'+k;
                        if(root->Child[k])
                             backtracking(nr, nc, board, ret, root->Child[k], prefix + c);
                    } 
            }
            else if(root->Child[board[nr][nc] - 'a']) 
            backtracking(nr, nc, board, ret, root->Child[board[nr][nc] - 'a'], prefix + board[nr][nc]);
        }
        board[row][col] = letter;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        TrieNode *root=new TrieNode();
        auto m = 4;
        auto n = 4;

        for(auto word: words) 
        {
            
            insert(root,word);
        }
        
        
        //for debugging
        
        
        
        string prefix="";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]=='*')
                {
                    for(int k=0;k<26;k++)
                    {
                        char c='a'+k;
                        if(root->Child[k])
                             backtracking(i, j, board, ret, root->Child[k], prefix + c);
                    }
                }
                else if(root->Child[board[i][j] - 'a']) 
                   backtracking(i, j, board, ret, root->Child[board[i][j] - 'a'], prefix + board[i][j]);
            }
        } 
        
        return ret;  
    }

    int main()
    {
        
        vector<vector<char>> board = {
                    {'c', '*', 't', 'f'},
                    {'r', 'a', 't', 'd'},
                    {'l', 'o', 'n', 'e'},
                    {'k', 'a', 'f', 'b'}
        };

        vector <string> dictonary  = { "start", "note", "sand", "stoned","cat","cut","danb","cot","coy","ptf","ptef","ppt","aaoa"};
        vector<string>ans= findWords(board,dictonary);

        for(auto x:ans) cout<<x<<" ";

    }
