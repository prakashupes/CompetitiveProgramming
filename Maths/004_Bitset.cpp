#include<iostream>
#include<bitset>
#include<vector>
#define max 1000000
typedef long long ll;
using namespace std;

class Prime
{
	public:
	bitset<1000001> b;
	vector <int> p;
	void seive();

};
void Prime :: seive() 
{
	b.set(); //1,1,1,1,....
	b[0]=0;
	b[1]=1;
	
	for(ll i=2;i*i<=max;i++)
	{
		if(b[i])
		{
			p.push_back(i);
			for(ll j=i*i;j<=max;j+=i)
			{
				b[j]=0;
			}
		}
	}

}

int main()
{
	int n;
	cin>>n;
	cout<<"First "<<n<<" primes: "<<endl;
	Prime pr;
	pr.seive();
	for(int i=0;i<=n;i++)
	{
		cout<<pr.p[i]<<" ";
	}


}

