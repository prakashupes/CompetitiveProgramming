#include<iostream>
#include <cmath> 
using namespace std;

//Standerd function to check if ppattern is present

bool isPreset(string str, string pat)
{
	return (str.find(pat)!=string::npos);

}

//Find all ocuarance using predefined

void all_Occ(string str,string pat)
{
	int n=str.length();
	int m=pat.length();
	
	size_t found =0;
	
	while(found<=m-n)
	{
		found=str.find(pat,found);
		if(found == string::npos) break;
		cout<<found<<" ";
		found++;
	
	}


}

void fill_lps(int lps[],string str)
{
	lps[0]=0;
	int n=str.length();
	int ln=0; //length of pattern
	int i=1;
	
	while(i<n)
	{
		if(str[ln]==str[i])
		{
			ln++;
			lps[i]=ln;
			i++;
		}
		else
		{
			if(ln==0)
			{
				lps[i]=ln;
				i++;
			}
			else
			{
				ln=lps[ln-1];
			
			}
		}
	
	
	}
	


}

void KMP(string str, string pat)
{
	
	
	int m=pat.length();
	int n=str.length();
	int lps[m];
	fill_lps(lps,pat);
	
	int i=0,j=0;
	while(i<n)
	{
		if(str[i]==pat[j])
		{
			i++;
			j++;
			
		}
		if(j==m)
		{
			cout<<(i-j)<<" ";
			j=lps[j-1];
		}
		
		else if(i<n && str[i]!=pat[j])
		{
			if(j==0)
			{
				i++;
			}
			else{
			
			j=lps[j-1];
			}
		}
	}

}
int main()
{
	
	string str="CREATE TABLE Persons (PersonID int, LastName varchar(255),FirstName varchar(255) not null primary key, Address varchar(255), City varchar(255));";
	string pat="primary key";
	
	//KMP(str,pat);
	//cout<<endl;
	//all_Occ(str,pat);
	
	//Using predifend find()
	cout<<isPreset(str,pat)<<endl;
	
	
}
