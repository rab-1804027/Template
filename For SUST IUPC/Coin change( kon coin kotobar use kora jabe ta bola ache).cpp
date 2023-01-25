#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int dp[n+1][x+1];
    int c[n+1],no[n+1];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>no[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j==0) dp[i][j]=0;
            else if(i==0) dp[i][j]=-1;
            else if(dp[i-1][j]>=0) dp[i][j]=0;
            else if(c[i]>j) dp[i][j]=-1;
            else if(dp[i-1][j-c[i]]>=0) dp[i][j]=1;
            else if(dp[i][j-c[i]]<no[i]&&dp[i][j-c[i]]>=0)
                dp[i][j]=dp[i][j-c[i]]+1;
            else
                dp[i][j]=-1;
        }
    }
    cout<<dp[n][x]<<endl;

}
/*
input
5 9
4 2 6 3 1
2 1 1 2 5
*/

