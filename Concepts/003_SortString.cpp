#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
bool my(
     string s1, 
     string s2){
     return s1<s2;
}

bool my2(
     char a,
     char b){
     return a<b;
}
int main(){

    string arr[]={
      "abc",
      "xyz",
      "apqr",
      "axyz",
      "zyax"
    
    };
    
    
    for(int i=0; i<5;i++){
    	sort(arr[i].begin(),arr[i].end(),my2);
    }
    
   
    sort(arr,arr+5,my);
    for(int i=0; i<5;i++){
    	cout<<arr[i]<<" ";
    }

}
