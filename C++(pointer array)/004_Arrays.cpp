#include<iostream>
using namespace std;


int f(int **twod )
int main()
{

    int arr[10];


    int *a = new int[10];

    int **two = new int*[5];

    for(int i=0  ; i<5 ; i++){
        two[i]= new int[10];
    }




    delete [] a;

    for(int i=0 ; i<5  ; i++){
        delete [] two[i];
    }

    delete [] two;

}

