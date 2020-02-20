#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_set <int> s;
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
     //Check if present
     auto a=s.find(2);
     if(a!=s.end())
     {
        cout<<*a<<endl;
     }
     else cout<<"Not present"<<endl;

     unordered_map<char , int> m;
     m['a']=1;
     m.insert({'b',2});
     m['c']=3;

     auto it=m.find('a');
     if(it!=m.end())
     {
        cout<<it->first<<" "<<it->second;
     }

}
