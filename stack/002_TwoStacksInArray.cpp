#include<iostream>
using namespace std;
//Push 1 : push into stack1
// Push 2:  push into stack2

template <class type>
class twoStack{
	int i=-1;
	int cap;
	int j;
	type *myStack;
	public:
	twoStack(int cap)
	{
		myStack=new type[cap];
		this->cap=cap;
		j=cap;
	}
	
	void push1(type data)
	{
		i++;
		if(i==j || i>=cap){
			cout<<"Stack 1 overflow"<<endl;
			cout<<" i:"<<i<<" j"<<j<<" cap"<<cap;
		}
		else{
			myStack[i]=data;
			
		}
		
	}
	void pop1()
	{
		if(i<0) cout<<"Stack1 underflow";
		else i--;
		
	}
	void push2(type data)
	{
		j--;
		if(i==j || j<0){
			cout<<"Stack 2 overflow"<<endl;
		}
		else{
			myStack[j]=data;
		
		}
		
	}
	void pop2()
	{
		if(j>=cap) cout<<"Stack2 underflow";
		else j++;
		
	}
	


};

int main()
{
	twoStack <int> s(1);
	s.push1(1);
	s.pop2();
	//s.pop2();
	
		

}
