#include<iostream>
using namespace std;

typedef struct TrieNode
{
    TrieNode *nodes[26];
   bool isEnd;

   TrieNode()
   {
       isEnd=false;
       for(int i=0;i<26;i++)
       {
           nodes[i]=NULL;
       }
   }
    
} TrieNode;

void insert(TrieNode *root, string word)
{
    TrieNode *ref=root;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(ref->nodes[index]==NULL)
        {
            ref->nodes[index]=new TrieNode();
        }
        ref=ref->nodes[index];
    }
    ref->isEnd=true;
}

bool search(TrieNode *root, string word)
{
    TrieNode *ref=root;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(ref->nodes[index]==NULL)
        {
            return false;
        }
        ref=ref->nodes[index];
    }
    return true; //not more relialable ... (read next line)
    //return (ref!=NULL && ref->isEnd); //Or if you want to search substring also then remove ref->end condition
}

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their","geek","geeks","cut","cat","but","bat","bats" };
    int n = sizeof(keys)/sizeof(keys[0]);
  
    struct TrieNode *root = new TrieNode();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
  
    // Search for different keys
    
    search(root, "bat")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "batse")? cout << "Yes\n" :
                           cout << "No\n";
                           
    return 0;
}