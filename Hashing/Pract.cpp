#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<vector<int>> v;
    vector<int> i;
    i.push_back(2);
    i.push_back(3);
    v.push_back(i);
    v.push_back(i);
    int j=0;
    for(vector<int> v1: v)
    {
      cout<<j;

        for(int x: v1)
        {
            cout<<"->"<<x;

        }
        cout<<endl;
        j++;

    }

}
