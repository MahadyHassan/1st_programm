#include<bits/stdc++.h>
using namespace std;
void print(int *A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
        if(i<n)
        {
            cout<<" ";
        }
    }
    cout<<endl;
}
void result_print(int array[], int Q)
{
    for(int i=0;i<Q;i++)
    {
        int L1, R1;
        cin>>L1>>R1;
        if(L1==1)
        {
            cout<<array[R1-1];
        }
        else
        {
            int r= array[R1-1]-array[(L1-1)-1];
            cout<<r;
        }
        cout<<endl;
    }
}
void prefix_sum_create(int* A, int *prefix, int N)
{
    if(A[0]<=0)
        prefix[0]=0;
    else
        prefix[0]=A[0];
    for(int i=1;i<N;i++)
    {
        if(A[i]>0)
            prefix[i]=prefix[i-1]+A[i];
        else
            prefix[i]=prefix[i-1];

    }
}
int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int prefix[N];
    prefix_sum_create(A,prefix,N);
    print(prefix,N);

    int Q;
    cin>>Q;
    result_print(prefix,Q);



    return 0;
}
