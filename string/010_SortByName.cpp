#include<iostream>
#include<algorithm>
using namespace std;

class Movie
{
    public:
    string name;
    int rating;
};

//Sort by name

bool name(Movie s1, Movie s2)
{
    return s1.name<s2.name;
}

bool rating(Movie s1, Movie s2)
{
    return s1.rating>s2.rating;
}
int main()
{
    //Array of Movie

    Movie arr[3];
    arr[0].name="3 Idiots";
    arr[0].rating=8;
    arr[2].name="Abc";
    arr[2].rating=7;
    arr[1].name="Idiots";
    arr[1].rating=9;

    cout<<"Before sorting"<<endl;
     for(Movie s: arr)
    {
        cout<<s.name<<" ";
    }
    cout<<"\nSort by name"<<endl;
    //sort by name

    sort(arr,arr+3,name);
    for(Movie s: arr)
    {
        cout<<s.name<<" "<<s.rating<<endl;
    }
    cout<<"\nSort by Rating"<<endl;
    //sort by name

    sort(arr,arr+3,rating);
    for(Movie s: arr)
    {
        cout<<s.name<<" "<<s.rating<<endl;
    }

}
