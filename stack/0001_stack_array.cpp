//crate an stack of capacity n using array
//stack(10); created a atsck of capacity 10;
//push,pop,top,is_Empty() operations()

#include <iostream>
using namespace std;
/* revision of concept
template <class type>
class Myclas
{
    public:
    type a;
    // Member initializer list
    Myclas (type aa) : a (aa) {};
   Myclas();
    type fun()
    {
        return this->a*2;
    }
};

int main()
{
   // cout<<take_par(2.5);
   Myclas <int> obj(2);

   cout<<obj.fun();
}
*/

/*
simple take an array of size n. and take a vairable called  top=-1 
For push : arr[curr]=nuber; top++;
Pop: top--;
peek: arr[top];
isEmpt : if(top==-1)

Time coplexity: push and pop both works in O(1)

*/
template <class type>
class My_stack{
    type *arr; //we can use vector so that we do not need to use size;
    
    int top;
    int n;
    public:
    My_stack(int n)
    {
        arr=new type(n);
        top=-1;
    }

    void push(type data)
    {
        if(top>n)
        {
            cout<<"Stack overflow\n";
            return;
        }
        top++;
        arr[top]=data;
        return;
    }
    type pop()
    {
        if(top==-1) return -1; //Under flow
        top--;
        return arr[top];
    }
    type peek()
    {
        if(top!=-1) return arr[top];
        return -1; //empty stack

    }
    bool isEmpty()
    {
        return top==-1 ? true:false;

    }
    


};
int main()
{
    My_stack<int> s(2);
    cout<<s.isEmpty()<<endl;
    s.push(2);
    s.push(3);
    s.pop();
    s.push(2);
    s.push(3);
    cout<<s.isEmpty()<<endl;
    
    cout<<s.peek();
}

