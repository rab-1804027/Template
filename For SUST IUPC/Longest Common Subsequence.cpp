#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,k;
    cin>>n>>k;
    string st,stt;
    cin>>st>>stt;
    int dp[n+1][k+1];
    for(int i=n;i>=0;i--)
    {
        for(int j=k;j>=0;j--)
        {
            if(j==k) dp[i][j]=0;
            else if(i==n) dp[i][j]=0;
            else if(st[i]!=stt[j])
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            else
                dp[i][j]=1+dp[i+1][j+1];
        }
    }
    cout<<dp[0][0]<<endl;
    for(int i=0,j=0;i<n&&j<k;)
    {
        if(dp[i][j]==dp[i+1][j+1]+1&&dp[i][j]!=dp[i][j+1]&&dp[i][j]!=dp[i+1][j])
        {
            cout<<stt[i];
            i++;j++;
        }
        else if(dp[i][j]==dp[i][j+1])
            j++;
        else
            i++;
    }
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
            cout<<dp[i][j]<< " ";
        cout<<endl;
    }

}
/*
input:
6 10
ecdixj
abcdefghij
*/
