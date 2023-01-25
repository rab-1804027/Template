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
#define 	yes 	    cout<<"YES"<<endl
#define 	no 	        cout<<"NO"<<endl
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

#define lx 300001
int a[lx],tree[3*lx];

int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
        return 0;
    else if(i<=b&&e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int x=query(left,b,mid,i,j);
    int y=query(right,mid+1,e,i,j);
    return x+y;
}

void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e||i<b)
        return ;
    else if(b==i&&e==i)
    {
        tree[node]=newvalue;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

void segtree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    segtree(left,b,mid);
    segtree(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void solve()
{
   // freopen ("(input).txt" , "r",  stdin) ;
    string st,stt;
    int low=0,high=0;
    int l,r; char ch;
    int n,k,t,x,y,z,d=0,cnt=0,temp=0,sum=0,f=0,flag=0;
    cin>>n ; vect v  ; sett s ; mapp m,mm ; pairr p ;
    loop(i,n) cin>>a[i+1];
    segtree(1,1,n);
    update(1,1,n,5,10);
    temp=query(1,1,n,3,6);
    cout<<temp<<endl;

}

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}



