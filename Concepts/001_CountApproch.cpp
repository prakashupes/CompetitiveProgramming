/**
the questioner will ask you Q queries, in each query He will give you a number ,
 and you have to tell him the total number of occurrences of that number in the array of numbers shown to your team .
 If the number is not present , then you will have to say “NOT PRESENT” (without quotes).


SAMPLE INPUT

6
1 1 1 2 2 0
6
1
2
1
0
3
4


SAMPLE OUTPUT

3
2
3
1
NOT PRESENT
NOT PRESENT

*/

    #include<iostream>
    using namespace std;
    #define max 1001
    int main()
    {
        int arr[max]={0};
        int N;

        cin>>N;

        for(int i=0;i<N;i++)
        {

            int ni;
            cin>>ni;
            arr[ni]++;


        }

        int Q;
        cin>>Q;
        while(Q>0)
        {

            int a;
            cin>>a;
            if(arr[a])
                cout<<arr[a]<<endl;
            else
                cout<<"NOT PRESENT"<<endl;
            Q--;
        }


    }

