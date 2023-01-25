///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using    namespace __gnu_pbds;
using    namespace std;

#define     FAST            ios::sync_with_stdio(0); cin.tie(0)
#define     int 	        long long
#define 	pb 	            push_back
#define 	pi 	            2*acos(0.0)
#define     scan(i)         scanf("%lld",&i)
#define     scann(i,j)      scanf("%lld%lld",&i,&j)
#define     print(i)        printf("%lld\n",i)
#define     printt(i,j)     printf("%lld %lld\n",i,j)
#define     loop(i,n) 	    for(int i = 0 ; i <n ; i++)
#define     rev(v)          reverse(v.begin(),v.end())
#define     reset(a,b)      memset(a,b,sizeof(a))
#define 	vect 	        vector<int>
#define     sorta(v)        sort(v.begin(),v.end())
#define     sortd(v)        sort(v.begin(),v.end(),greater<>())
#define     sorted(v)       is_sorted(v.begin(),v.end())
#define     mnv(v)          *min_element(v.begin(),v.end())
#define     mxv(v)          *max_element(v.begin(),v.end())
#define     countv(v,a)     count(v.begin(),v.end(),a)
#define     vplusa(v,a)     v.insert(v.end(),a.begin(),a.end())
#define 	mapp 	        map<int,int>
#define     rmap            map<int,int,greater<>>m
#define 	pairr 	        pair<int,int>
#define 	sett	        set<int>
#define     rset            set<int,greater<>>s
#define     setp(x)         fixed<<setprecision(x)
#define     digit(n)        floor(log10(n)+1)
#define     bdigit(n)       floor(log2(n)+1)
#define 	yes 	        cout<<"YES"<<endl
#define 	no 	            cout<<"NO"<<endl
#define 	ff 	            first
#define 	ss 	            second
#define     mx              INT_MAX
#define     lmx             LLONG_MAX
#define     mn              INT_MIN
#define     lmn             LLONG_MIN
#define     ub              upper_bound
#define     lb              lower_bound
#define     mod             1000000007

inline void normal(int &a) { a %= mod; (a < 0) && (a += mod); }
inline int modMul(int a, int b) { a %= mod, b %= mod; normal(a), normal(b); return (a*b)%mod; }
inline int modAdd(int a, int b) { a %= mod, b %= mod; normal(a), normal(b); return (a+b)%mod; }
inline int modSub(int a, int b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline int modInverse(int a) { return modPow(a, mod-2); }
inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }
inline int ncr(int n, int r){int a=max(n-r,r),val=1,d=1; while(n>a) val*=n,val/=d,n--,d++; return val;}

template <typename T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {return a*(b/gcd(a,b));}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define lx 101
int node,edge;
int adj[lx][lx],path[lx][lx];
vect way;

vect findpath(int i,int j)
{
    way.pb(i);
    while(i!=j)
    {
        i=path[i][j];
        way.pb(i);
    }
    return way;
}

void floydwarshall()
{
    for(int k=1;k<=node;k++)
    {
        for(int i=1;i<=node;i++)
        {
            for(int j=1;j<=node;j++)
            {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                    path[i][j]=path[i][k];
                }
                //othoba evabe lekha jabe adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}

void solve()
{
    int cnt=0,temp=0,sum=0,ans=0;
    cin>>node>>edge;
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(i!=j) adj[i][j]=mx;
            path[i][j]=j;
        }
    }
    loop(i,edge)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x][y]=w; //for directed...undirected hole adj[y][x]=w etao hobe
    }
    floydwarshall();
    int x,y;
    cin>>x>>y;
    findpath(x,y);
    cout<<adj[x][y]<<endl; //cost
    for(auto i:way) cout<<i<< " ";
    cout<<endl;
}
/*
4 8
1 2 3
2 1 2
2 3 2
3 2 5
4 1 20
4 3 8
3 4 2
2 4 1
*/

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
