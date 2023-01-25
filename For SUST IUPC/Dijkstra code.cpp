///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define     FAST        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     int 	    long long
#define 	pb 	        push_back
#define     pp          pop_back
#define 	mp 	        make_pair
#define 	pi 	        2*acos(0.0)
#define     scan(i)     scanf("%lld",&i)
#define     scann(i,j)  scanf("%lld%lld",&i,&j)
#define     print(i)    printf("%lld\n",i)
#define     printt(i,j) printf("%lld %lld\n",i,j)
#define     loop(i,n) 	for(int i = 0 ; i <n ; i++)
#define     loopp(i,n) 	for(int i = 1 ; i <n ; i++)
#define     rep(i,n)    for(int i=n-1;i>=0;i--)
#define     reset(a,b)    memset(a,b,sizeof(a))
#define 	vect 	    vector<int>
#define 	vec_it 	    vector<int>::reverse_iterator vi
#define     sorta(v)    sort(v.begin(),v.end())
#define     sortd(v)    sort(v.begin(),v.end(),greater<>())
#define     sorted(v)   is_sorted(v.begin(),v.end())
#define 	mapp 	    map<char,int>
#define     rmap        map<int,int,greater<>>m
#define 	pairr 	    pair<int,int>
#define 	sett	    set<int>
#define     rset        set<int,greater<>>s
#define 	set_it 	    set<int>::reverse_iterator si
#define     map_it      map<int,int> :: reverse_iterator mi
#define     digit(n)    floor(log10(n)+1)
#define 	yes 	    cout<<"YES"<<endl
#define 	no 	        cout<<"NO"<<endl
#define 	ff 	        first
#define 	ss 	        second
#define     mx          INT_MAX
#define     lmx         LLONG_MAX
#define     mn          INT_MIN
#define     lmn         LLONG_MIN
#define     inf         0x3f3f3f3f
#define     GCD         __gcd(a,b)
#define     LCM         (a/GCD)*b
template <typename T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {return a*(b/gcd(a,b));}
int modulo (int a, int b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }

int node,edge,cnt,temp,cost;
map<int,vector<pair<int,int>>>v;
int dis[200005];

void dijkstra(int start)
{
    priority_queue<pairr,vector<pairr>,greater<pairr>> q;
    reset(dis,inf);
    q.push(mp(0,start));
    dis[start]=0;
    while(!q.empty())
    {
        int n=q.top().ss;
        int d=q.top().ff;
        q.pop();
        if(d>dis[n])
            continue;
        for(int i=0;i<v[n].size();i++)
        {
            int a=v[n][i].ff;
            int b=v[n][i].ss;
            if(d+a<dis[b])
            {
                dis[b]=d+a;
                q.push(mp(dis[b],b));
            }
        }
    }


}


void solve()
{
   // freopen ("(input).txt" , "r",  stdin) ;
    string st,stt ;
    int l,r; char ch;
    int n,k,t,b,x,y,z,d=0,sum=0,f=0;
    cin>>node>>edge;
    loop(i,edge)
    {
        cin>>x>>y>>cost;
        v[x].pb(make_pair(cost,y));
        v[y].pb(make_pair(cost,x));
    }
    dijkstra(1);
    for(int i=1;i<=node;i++)
        cout<<dis[i]<<endl;

}

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
/*
input:
4 4
1 2 2
1 3 5
2 3 1
4 3 3
*/
