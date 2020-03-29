#include <bits/stdc++.h>
using namespace std;
template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}
bool anagram(string str1, string str2)
{
    if(str1.length()!=str2.length())
    {
        return false;
    }
    map <char,int> m1;
    map <char,int> m2;
    
    for(int i=0;i<str1.length();i++)
    {
        m1[str1[i]]++;
    }
    for(int i=0;i<str2.length();i++)
    {
        m2[str2[i]]++;
    }
    return map_compare(m1,m2);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string str1;
	    cin>>str1;
	    string str2;
	    cin>>str2;
	    if(anagram(str1,str2))
	    {
	        cout<<"YES"<<endl;
	        
	    }
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}
