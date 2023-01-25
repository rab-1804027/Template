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
#define     rev(v)      reverse(v.begin(),v.end())
#define     reset(a,b)  memset(a,b,sizeof(a))
#define 	vect 	    vector<int>
#define 	vec_it 	    vector<int>::reverse_iterator vi
#define     sorta(v)    sort(v.begin(),v.end())
#define     sortd(v)    sort(v.begin(),v.end(),greater<>())
#define     sorted(v)   is_sorted(v.begin(),v.end())
#define 	mapp 	    map<int,int>
#define     rmap        map<int,int,greater<>>m
#define 	pairr 	    pair<int,int>
#define 	sett	    set<int>
#define     rset        set<int,greater<>>s
#define 	set_it 	    set<int>::reverse_iterator si
#define     map_it      map<int,int> :: reverse_iterator mi
#define     digit(n)    floor(log10(n)+1)
#define 	yes 	    cout<<"Yes"<<endl
#define 	no 	        cout<<"No"<<endl
#define 	ff 	        first
#define 	ss 	        second
#define     mx          INT_MAX
#define     lmx         LLONG_MAX
#define     mn          INT_MIN
#define     lmn         LLONG_MIN
#define     inf         0x3f3f3f3f
#define     inff        10e18
#define     GCD         __gcd(a,b)
#define     LCM         (a/GCD)*b
template <typename T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {return a*(b/gcd(a,b));}
int modulo (int a, int b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }

int dx[]={0,1,0,-1,1,-1,1,-1};
int dy[]={1,0,-1,0,1,1,-1,-1};
int vis[500][500],dis[500][500];
map<int,vect>v; int n;

void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty())
    {
        pairr p=q.front();
        q.pop();
        int x=p.ff,y=p.ss;
        for(int i=0;i<8;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<n&&b>=0&&b<n&&vis[a][b]==0)
            {
                dis[a][b]=dis[x][y]+1;
                vis[a][b]=1;
                q.push({a,b});
            }
        }
    }
}

void solve()
{
   // freopen ("(input).txt" , "r",  stdin) ;
    string st,stt,str;
    int low=0,high=0;
    int l,r; char ch;
    int k,t,x,y,z,d=0,cnt=0,temp=0,sum=0,f=0,flag=0;
    cin>>n ; vect vv ,a ; sett s ; mapp m,mm ; pairr p ;
    loop(i,n)
    {
        loop(j,n)
        {
            cin>>x;
            v[i].pb(x);
        }
    }
    bfs(0,0);
    cout<<dis[n-1][n-1]<<endl;

}
/*
intput
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
output 3 jehetu diagonally o jete parbe..shudhu up,down,left,right hole ans output hobe 6
*/

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
