#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Hash
{   public:
    int BUCKET;
    list<int> *table;

    Hash(int BUCKET)
    {
        this->BUCKET=BUCKET;
        table=new list<int>[BUCKET];
    }
    int hashFunction(int key)
    {
        return key%BUCKET;
    }
    void insertKey(int key)
    {
        int index=hashFunction(key);
        table[index].push_back(key);

    }
    void display()
    {
        for(int i=0;i<BUCKET;i++)
        {

            for(int value:table[i])
            {
                cout<<value<<"->";
            }
            cout<<endl;
        }
        }

    void deleteKey(int key)
    {
        int index=hashFunction(key);
        table[index].remove(key);

    }




};

int main()
{
    int arr[]={3,4,5,9,7,4,55,6,2,3,7,8,9};
    int siz=sizeof(arr)/sizeof(arr[0]);
    Hash h(5);
    for(int i=0;i<siz;i++)
    {
        h.insertKey(arr[i]);
    }
    h.display();
    h.deleteKey(55);
    h.display();

}
