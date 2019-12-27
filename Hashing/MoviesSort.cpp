#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Movies
{
    public:
    string name;
    int year;

};

bool sortByYear(Movies m1, Movies m2)
{

    return m1.year>m2.year;
}
bool sortByName(Movies m1, Movies m2)
{

    return m1.name>m2.name;
}

int main()
{
    Movies m[3];
    cout<<"Enter Name and year Of ";
    for(int i=0;i<3;i++)
    {
        cout<<(i+1)<<"th Movie"<<endl;
        getline(cin,m[i].name);
        cin>>m[i].year;
    }
    cout<<"You Entered\n";
    for(int i=0;i<3;i++)
    {
        cout<<m[i].name<<" "<<m[i].year<<endl;
    }

}
