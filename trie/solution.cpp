#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#define M 4
#define N 4
using namespace std;


//offset use for 8 directions
const vector<int> row_offset = { -1, -1, -1, 0, 1, 0, 1, 1 };
const vector<int> col_offset =  { -1, 1, 0, -1, -1, 1, 0, 1 };

//Utility Functions:
unordered_map<string,bool> getDictionary(); //Utility Methods to read dictionary from file and it returns a map of string and bool
vector<vector<char>> getBoard();    //Utility Methods to read dictionary from file and it returns a board


/***********************Trie Data Structure Part**********************/
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
    
    return (ref->isEnd);
}


// A backtracing method to solve the boggle word problem

void boggle_solver(int row, int col, vector<vector<char>> board, unordered_map<string,bool>& dict, TrieNode* root, const string& prefix)
{
    if(root->isEnd){
        dict[prefix]=true;
        root->isEnd = false; //to avoid duplicate the word
    }
    char letter = board[row][col]; 
    board[row][col] = '$';
    for(int d = 0; d < 8; d++){
        int nr = row + row_offset[d]; 
        int nc = col + col_offset[d];  
        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4 )  continue;
        if(board[nr][nc] == '$') continue;
        if(board[nr][nc]=='*')
        {
            for(int k=0;k<26;k++)
                {
                    char c='a'+k;
                    if(root->Child[k])
                        boggle_solver(nr, nc, board, dict, root->Child[k], prefix + c);
                } 
        }
        else if(root->Child[board[nr][nc] - 'a']) 
            boggle_solver(nr, nc, board, dict, root->Child[board[nr][nc] - 'a'], prefix + board[nr][nc]);
        }
        board[row][col] = letter;
    }
    

//Helper function

void helper(vector<vector<char>>& board,unordered_map<string,bool>& dict) {
        
        TrieNode *root=new TrieNode();
        for(auto x: dict) 
        {
            
            insert(root,x.first);
        }
        
        string prefix="";
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(board[i][j]=='*')
                {
                    for(int k=0;k<26;k++)
                    {
                        char c='a'+k;
                        if(root->Child[k])
                             boggle_solver(i, j, board, dict, root->Child[k], prefix + c);
                    }
                }
                else if(root->Child[board[i][j] - 'a']) 
                   boggle_solver(i, j, board, dict, root->Child[board[i][j] - 'a'], prefix + board[i][j]);
            }
        } 
        
        return ;  
    }



//Part-1 solution : Check if user entered word is valid and present in board
void findWord(unordered_map<string,bool>dict)
{
    cout<<"Enter word to search in board: ";
    string str;
    cin>>str;

    if(dict.find(str)!=dict.end() && dict[str]==true)
    {
        cout<<"Word founded and present in the dictonary/valid word"<<endl;
    }
    else
    {
        cout<<"Word is not present in Board\n";
    }

}

//print all solution
void printAllWords(unordered_map<string,bool>dict)
{
    cout<<"\nPrinting all posible words present in dictonary :"<<endl;
    for(auto x:dict)
    {
        if(x.second==true) cout<<x.first<<" ";
    }
    cout<<endl;
}



//Main Driver Method
int main()
{

        unordered_map<string,bool> dict= getDictionary();
        vector<vector<char>> board = getBoard();
        helper(board,dict);
        /*
        To run manually one by one metods you can comment one of the following
        */
        
        findWord(dict);
        printAllWords(dict);

    }



//defination of utility functions
//Method to get all words from file    
unordered_map<string,bool> getDictionary()
{
    unordered_map<string,bool> dict;

    ifstream file;
    file.open("dictionary.txt");
    if(!file.is_open()) {
        cout<<"Error in file opening.. \n**File colud be in diffent location or not exist in same foldar\n";
        exit(1);
    }
    char ch;
    string s="";
    while(file.get(ch)) //abc,pqr
    {
        if(ch==',')
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            dict.insert({s,false});
            s="";
        }
        else
        {
             s+=ch;
        }  
    }
    file.close();
    return dict;
}

//utility methods to make board from input file
vector<vector<char>> getBoard()
{  
    vector<vector<char>> board(4);
    for(int i=0;i<4;i++)
    {
        board[i] = vector<char>(4);
    }

    ifstream file;
    file.open("board.txt");
    if(!file.is_open()) {
        cout<<"Error in file opening.. \n**File colud be in diffent location or not exist in same foldar\n";
        exit(1);
    }
    char ch;
    string s="";
    while(file.get(ch)) //a,b,c,d,e
    {
        if(ch!=',')
        {
            s+=ch;
            
           
        }
    }
       transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        if(s.length()!=16)
        {
            cout<<"Provided Board file is not as Assumtion\n";
            exit(1);
        }
        int k=0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                board[i][j]=s[k];
                k++;
            }
        }
        
    file.close();
    return board;

}

