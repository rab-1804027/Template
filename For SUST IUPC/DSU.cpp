#include<bits/stdc++.h>
using namespace std;

#define lx 100005
int parent[lx],sz[lx];

int Find_Set(int u)
{
    if(u==parent[u])
        return u;
    else
        return parent[u]=Find_Set(parent[u]); //Path compression
}

int Union(int u,int v)
{
    if(sz[u]<sz[v]) swap(u,v);
    parent[v]=u;
    sz[u]+=sz[v]; //union by size, complexity O(1)
}

main()
{
    int node,edge,u,v;
    cin>>node>>edge;
    for(int i=1;i<=node;i++)
        parent[i]=i,sz[i]=1;
    for(int i=1;i<=edge;i++)
    {
        cin>>u>>v;
        u=Find_Set(u);
        v=Find_Set(v);
        if(u!=v)
            Union(u,v);
    }
}
