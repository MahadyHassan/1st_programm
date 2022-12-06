#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, k;
    cin>>N>>k;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    for(int i=1;i<N;i++)
    {
        int key=A[i];
        int j=i-1;
        while(A[j]>key && j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;

    }

    int min=A[k-1];
    int max=A[N-k];
    cout<<min<<endl;
    cout<<max<<endl;





    return 0;
}
