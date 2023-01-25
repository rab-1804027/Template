#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    bool dp[n+1][x+1];
    int c[n+1];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j==0)
                dp[i][j]=true;
            else if(i==0)
                dp[i][j]=false;
            else if(c[i]>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                if(dp[i-1][j]==true)
                    dp[i][j]=true;
                else
                    dp[i][j]=dp[i-1][j-c[i]];
            }
        }
    }
    if(dp[n][x]==true)
    {
        cout<<"yes\n";
        int i=n,j=x;
        while(i&&j)
        {
            if(dp[i-1][j]==true)
            {
                i--;continue;
            }
            cout<<c[i]<< " ";
            j-=c[i];i--;
        }
        cout<<endl;
    }
    else
        cout<<"no\n";

}
/*
input
5 9
1 1 4 2 3
*/

