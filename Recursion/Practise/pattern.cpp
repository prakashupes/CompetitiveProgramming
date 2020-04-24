#include <iostream>
using namespace std;
void print_pattern(int n)
{
if (!(n > 0))
{
cout << n << " ";
return;
}

cout << n << " ";
n -= 5;

print_pattern(n);

n += 5;
cout << n << " ";
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int i;
	    cin>>i;
	    print_pattern(i);
	    cout<<endl;
	}
	return 0;
}
