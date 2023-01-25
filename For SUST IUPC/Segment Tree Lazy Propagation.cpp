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

#define lx 100005
int a[lx];
int tree[4*lx],prop[4*lx];
int query(int node,int b,int e,int i,int j,int carry)
{
    if(i>e||j<b)
        return 0;
    else if(i<=b&&e<=j)
    {
        return tree[node]+carry;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int x=query(left,b,mid,i,j,carry+prop[node]);
    int y=query(right,mid+1,e,i,j,carry+prop[node]);
    return max(x,y);
}

void update(int node,int b,int e,int i,int j,int value)
{
    if(i>e||j<b)
        return;
    else if(i<=b&&e<=j)
    {
        tree[node]+=value;
        prop[node]+=value;
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,value);
    update(right,mid+1,e,i,j,value);
    tree[node]=max(tree[left]+prop[node],tree[right]+prop[node]);
}

void segtree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    segtree(left,b,mid);
    segtree(right,mid+1,e);
    tree[node]=max(tree[left],tree[right]);
}

void solve()
{
   // freopen ("(input).txt" , "r",  stdin) ;
    string st,stt,str;
    int low=0,high=0;
    int l,r; char ch;
    int n,k,t,x,y,z,d=0,cnt=0,temp=0,sum=0,f=0,flag=0;
    cin>>n ; vect v ; sett s ; mapp m,mm ; pairr p ;
    for(int i=1;i<=n;i++) a[i]=0;
    reset(tree,0),reset(prop,0);
    segtree(1,1,n);
  //  update(1,1,n,1,7,2); //1 theke 4 range er sobar sathe 5 add korte hobe
  //  update(1,1,n,1,4,3);
    update(1,1,n,2,4,1); //1 theke 4 range er sobar sathe 5 add korte hobe
    update(1,1,n,3,4,1);
    update(1,1,n,1,4,1);
    update(1,1,n,4,5,1);
    temp=query(1,1,n,1,4,0); //1 theke 4 prjnto sum ber korbo,,carry initially 0

    cout<<temp<<endl;


}

/*input
7
4 -9 3 7 1 0 2
*/

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
