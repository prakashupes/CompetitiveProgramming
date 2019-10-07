
#include<iostream>
#include <vector>
#define ll long long
using namespace std;
static ll MAX_SIZE=100;

int main()
{

	ll arr[MAX_SIZE];
	for(ll i=0;i<MAX_SIZE;i++)
	{
		arr[i]=1;
	}
	arr[0]=arr[1]=0;

	for(ll i=2;i*i<MAX_SIZE;i++)
    {

        if(arr[i]==1)
        {
            for(ll j=i*i;j<MAX_SIZE;j+=2*i)
            {
                arr[i]=0;

            }

        }
    }

     vector<ll> v;
     for(ll i=0;i<MAX_SIZE;i++)
     {
         if(arr[i]==1)
         {
             v.push_back(i);
         }

     }
     cout<<v.at(0);


}
