#include<iostream>
using namespace std;

int s(int **arr, int n, int m ){

        int count=0;
    for(int i=0 ; i<n  ; i++){
        for(int j=0  ; j<m ; j++){
            arr[i][j]=count++;
        }
    }
}

int main()
{
    int *arr = new int[10];

    int **twod =  new int*[2];

    for(int i=0 ; i<2  ; i++){
        twod[i]=new int[3];
    }

    cout<<s(twod,2,3)<<endl;

    for(int i=0 ; i<2  ; i++){
        for(int j=0  ; j<3 ; j++){
            cout<<twod[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0 ; i<2  ; i++){
        delete [] twod[i];
    }

    delete twod;

}

