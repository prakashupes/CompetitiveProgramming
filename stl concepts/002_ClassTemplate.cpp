#include<iostream>
#include<vector>
using namespace std;

template<typename T> //We create a generic vector array
class Generic{
public:
    int Size;

    vector<T> *arr;

    Generic(int s)
    {
        this->Size=s;
        arr=new vector<T>[s];
    }
    void addElement(int i,vector<T> v)
    {
        arr[i]=v;
    }

    void printArray()
    {
        for(int i=0;i<Size;i++)
        {
            for(auto x:arr[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }



};

int main()
{
    vector<int> v1={1,2,3};
    vector<string> v2={"asd","ghgj"};
    Generic<int> g(2);
    g.addElement(0,v1);
    g.addElement(1,v1);
    g.printArray();

}
