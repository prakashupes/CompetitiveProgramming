/*This is a function problem.You only need to complete the function given below*/
//Complete this function
void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{
    //Your code here

    for(int i=0;i<sizeOfArray;i++)
    {
        int index=arr[i]%hashSize;
        if(hash[index]==-1)
        {
            hash[index]=arr[i];
        }
        else
        {
            index=(index+1)%hashSize;
            while(hash[index]!=-1)
            {
                index=(index+1)%hashSize;
            }
            hash[index]=arr[i];
        }

    }
}






void linearProbing(int A[],int hs,int a[],int n)
{
    int i,j,x,var;
    for(i=0;i<hs;i++) A[i]=-1;
    for(i=0;i<n;i++)
    {
        j=0;
        x=a[i];
        var=x%hs;
        if(A[(var+j)%hs]==-1) A[var]=x;
        else if(A[(var+j)%hs]!=-1)
        {
            while(A[(var+j)%hs]!=-1)
            {
                j++;
            }
            if(A[(var+j)%hs]==-1) A[(var+j)%hs]=x;
        }
    }
}
