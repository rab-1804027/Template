#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int dp[n+1][x+1];
    int w[n+1],c[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>c[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(!i||!j)
            {
                dp[i][j]=0;continue;
            }
            if(w[i]>j) dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j-w[i]]+c[i],dp[i-1][j]);
        }
    }
    cout<<dp[n][x]<<endl;

}
/*
input
4 7
1 1
5 7
3 4
4 5
*/
