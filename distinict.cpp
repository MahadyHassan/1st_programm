#include<bits/stdc++.h>
using namespace std;
int sum(int *arr, int n)
{
    int sum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(sum<arr[i])
        {
            sum=arr[i];
        }
    }
    return sum;
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
    int sume=sum(A,N);

    int dist[sume+1]={0};
    for(int i=0;i<N;i++)
    {
        int key=A[i];
        dist[key]++;
    }
    int dist_number=0;
    for(int i=0;i<=sume;i++)
    {
        if(dist[i]>0)
        {
            dist_number++;
        }
    }
    cout<<dist_number;






    return 0;
}
