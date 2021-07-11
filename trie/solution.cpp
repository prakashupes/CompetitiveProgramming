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
unordered_map<string,bool> getdictionaryionary(); //Utility Methods to read dictionaryionary from file and it returns a map of string and bool
vector<vector<char>> getBoard();    //Utility Methods to read dictionaryionary from file and it returns a board
void printBoard(vector<vector<char>>);
void printDicitonary(unordered_map<string,bool>);
unordered_map<string,bool> getdictionaryionaryFromFile(); //Utility Methods to read dictionaryionary from file and it returns a map of string and bool
vector<vector<char>> getBoardFromFile();  

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

void boggle_solver(int row, int col, vector<vector<char>> board, unordered_map<string,bool>& dictionary, TrieNode* root, const string& prefix)
{
    if(root->isEnd){
        dictionary[prefix]=true;
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
                        boggle_solver(nr, nc, board, dictionary, root->Child[k], prefix + c);
                } 
        }
        else if(root->Child[board[nr][nc] - 'a']) 
            boggle_solver(nr, nc, board, dictionary, root->Child[board[nr][nc] - 'a'], prefix + board[nr][nc]);
        }
        board[row][col] = letter;
    }
    

//Helper function

void helper(vector<vector<char>>& board,unordered_map<string,bool>& dictionary) {
        
        TrieNode *root=new TrieNode();
        for(auto x: dictionary) 
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
                             boggle_solver(i, j, board, dictionary, root->Child[k], prefix + c);
                    }
                }
                else if(root->Child[board[i][j] - 'a']) 
                   boggle_solver(i, j, board, dictionary, root->Child[board[i][j] - 'a'], prefix + board[i][j]);
            }
        } 
        
        return ;  
    }



//Part-1 solution : Check if user entered word is valid and present in board
void findWord(unordered_map<string,bool>dictionary)
{
    cout<<"Enter word to search in board: ";
    string str;
    cin>>str;

    if(dictionary.find(str)!=dictionary.end() && dictionary[str]==true)
    {
        cout<<"Word founded and present in the dictionaryonary/valid word"<<endl;
    }
    else
    {
        cout<<"Word is not present in Board\n";
    }

}

//print all solution
void printAllWords(unordered_map<string,bool>dictionary)
{
    cout<<"\nPrinting all posible words :"<<endl;
    for(auto x:dictionary)
    {
        if(x.second==true) cout<<x.first<<" \n";
    }
    cout<<endl;
}



//Main Driver Method
int main()
{
        cout<<"Instructions:\n1. Please un-comment line #177 and #178 and comment line #174 and #175 to take input from file"<<endl;
        cout<<"2. Please place you manual files in same foldar as solution.cpp"<<endl;

        //unordered_map<string,bool> dictionary= getdictionaryionary();
        //vector<vector<char>> board = getBoard();
		
		unordered_map<string,bool> dictionary= getdictionaryionaryFromFile();
        vector<vector<char>> board = getBoardFromFile();
		
		printBoard(board);
		printDicitonary(dictionary);
		
        helper(board,dictionary);
        findWord(dictionary);
        printAllWords(dictionary);

    }



/***********************defination of utility functions*******************/
//Method to get all words from file 

 unordered_map<string,bool>  getdictionaryionary()
 {
	 unordered_map<string,bool> dict;// getDictionary();
     dict["geek"]=false;
     dict["love"]=false;
     dict["loves"]=false;
     dict["boat"]=false;
     dict["boss"]=false;
     dict["loss"]=false;
     dict["lose"]=false;
     dict["gizy"]=false;
     dict["awer"]=false;
     dict["eeqpe"]=false;
	 dict["ray"]=false;
	 dict["rise"]=false;
	 dict["stop"]=false;
	 return dict;
	 
 }
 vector<vector<char>> getBoard(){
			vector<vector<char>> board ={{'g', 'i', 'z','*'},
                                    {'b', 'o', '*','s'},
                                    {'q', 'r', 'e','s'},
                                    {'l', 'o', 'v','*'}};
			return board;
}

void printBoard( vector<vector<char>> board)
{
	cout<<"Board Is:"<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
		
}

void printDicitonary( unordered_map<string,bool> dictionary)
{
	cout<<"Dictionary Is:\n{";
	for(auto x: dictionary) 
        {
            
            cout<<x.first<<", ";
        }
	cout<<"}"<<endl;
        
	
}
   
unordered_map<string,bool> getdictionaryionaryFromFile()
{
    unordered_map<string,bool> dictionary;

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
            dictionary.insert({s,false});
            s="";
        }
        else
        {
             s+=ch;
        }  
    }
    file.close();
    return dictionary;
}

//utility methods to make board from input file
vector<vector<char>> getBoardFromFile()
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

