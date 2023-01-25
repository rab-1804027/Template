#include<bits/stdc++.h>
using namespace std;

#define lx 1001
int node,edge;
map<int,vector<int>>adj;
int Right[lx],Left[lx],vis[lx];

bool kuhn(int u)
{
    for(auto v:adj[u])
    {
        if(vis[v])
            continue;
        vis[v] = 1;
        if(Right[v]==-1 || kuhn(Right[v]))
        {
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }
    return false;
}

void BM()
{
    memset(Right,-1,sizeof(Right));
    memset(Left,-1,sizeof(Left));
    int cnt = 0;
    for(int i = 1; i <= node; i++)
    {
        memset(vis,0,sizeof(vis));
        if(kuhn(i))
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

main()
{
    int x,y;
    cin>>node>>edge;
    for(int i=1;i<=edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    BM();
}
