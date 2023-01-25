#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int dp[n+1][x+1];
    int c[n+1];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j==0) dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(c[i]>j) dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-c[i]];
        }
    }
    cout<<dp[n][x]<<endl;

}
/*
input
5 9
4 2 6 3 1
*/

