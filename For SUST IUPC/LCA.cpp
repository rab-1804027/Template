#include<bits/stdc++.h>
using namespace std;

#define pb push_back

#define lx 100005
vector<int>adj[lx];
int depth[lx],vis[lx];
int parent[lx],up[lx][33];

int lca(int a,int b)
{
    for(int i=31;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

int getkthancestor(int node,int k)
{
    if(depth[node]<k)
        return -1;
    for(int i=0;i<32;i++)
    {
        if(k&(1<<i))
        {
            node=up[node][i];
        }
    }
    return node;
}

void dfs(int node)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(vis[i]==0)
        {
            up[i][0]=node;
            parent[i]=node;
            for(int j=1;j<32;j++)
                up[i][j]=up[up[i][j-1]][j-1];
            depth[i]=depth[node]+1;
            dfs(i);
        }
    }
}

main()
{
    int n,u,v;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    getkthancestor(10,6); //10 er 6th ancestor
    //for finding lca
    //get same depth
    int a=6,b=10,k;
    if(depth[a]>depth[b])
        k=depth[a]-depth[b],a=getkthancestor(a,k);
    else
        k=depth[b]-depth[a],b=getkthancestor(b,k);
    cout<<lca(a,b)<<endl;

}
/*
10 6
1 2
1 3
1 4
2 5
2 6
3 7
7 8
7 9
9 10
*/
