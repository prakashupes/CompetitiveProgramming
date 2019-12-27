#include<iostream>
#include<list>
using namespace std;
class Check
{
    public:

    int a;
    char ch;

    void inserta(int p)
    {
        this->a=p;
    }
    void insertch(int ch)
    {
        ch=ch;
    }

};
int main()
{
    Check* c =new Check();
    c->inserta(5);
    cout<<c->a;
    cout<<c;

}
