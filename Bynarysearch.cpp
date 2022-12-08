#include<bits/stdc++.h>
using namespace std;
void print(int *A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
        if(i<n-1)
        {
            cout<<" ";
        }
    }
    cout<<endl;
}
int bynary_search(int *A, int lb, int hb, int k)
{
    if(lb<=hb)
    {
        int mid=(lb+hb)/2;
        if(A[mid]==k)
        {
           return mid;
        }
        else if(A[mid]<k)
        {
            bynary_search(A,mid+1,hb,k);
        }
        else
        {
            bynary_search(A,lb,mid-1,k);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int N,K;
    cin>>N>>K;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    print(A, N);
   int mid= bynary_search(A,0,N-1,K);
   cout<<mid+1<<endl;




    return 0;
}
