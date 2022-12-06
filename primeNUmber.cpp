#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for(int i=2;i<=N;i++)

    {
        int check=1;
        for(int j=2;j<N;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(i%j==0)
            {
                check=0;
                break;
            }
        }
        if(check==1)
        {
            cout<<i;
            if(i<N)
            {
                cout<<" ";
            }

        }
    }




    return 0;
}
