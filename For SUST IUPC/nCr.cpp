///Hello_World_Its_Rakib_Alam_Bappi
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define loop_i for(int i = 1 ; i <= t ; i++)
#define loop_j for(int j = 0 ; j <= n ; j++)
#define vectorr vector<int>v
#define vec_it vector<int>::iterator vi;
#define mapp map<int,int>m
#define pairr pair<int,int>p
#define sett set<int>s
#define set_it set<int>::iterator si
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define xx first
#define xy second
int dp[1000000][2];
int nCr(int n,int r)
{
    if(r==n)
        return 1;
    if(r==1)
        return n;
    if(dp[n][r]!=-1)
        return dp[n][r];
    else
    {
        dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
        return dp[n][r];
    }
}
main()
{
    /// freopen ("in.txt" , "r",  stdin) ;
    ///string st;
    int n,r,k,t,temp=0,cnt=0,x,y=0;
    cin>>n>>r;
    ///int dp[n][r];
    loop_j
    {
        for(int i=0;i<=r;i++)
            dp[j][i]=-1;
    }
    cout<<nCr(n,r);

}
