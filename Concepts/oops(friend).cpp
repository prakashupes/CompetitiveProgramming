#include<iostream>
using namespace std;

/* Case 1 when we cant access*
class A{
    private:
    int a;
    public:
};
class B : public A{
    void printA()
    {
        cout<<a; //this is an error
    }

};

*/
class A{
    private:
    int a=2;
    public:
    friend class B;
    friend class C;

};
class B : public A{
    public:
    void printA()
    {
        cout<<a<<endl; //we can direct access, since it is derived class
    }

};

class C{
    public:
    void printA()
    {
      //  cout<<a; // error becz it is not derived so we must create oject first; //a is not declerd error

        A a;
        cout<<a.a<<endl;

    }
};

int main()
{
    B b;
    C c;
    b.printA();
    c.printA();    

}