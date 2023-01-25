///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using    namespace __gnu_pbds;
using    namespace std;

#define     FAST            ios::sync_with_stdio(0); cin.tie(0)
#define     int 	        long long
#define 	pb 	            push_back
#define     ppb             pop_back
#define 	mp 	            make_pair
#define 	pi 	            2*acos(0.0)
#define     scan(i)         scanf("%lld",&i)
#define     scann(i,j)      scanf("%lld%lld",&i,&j)
#define     print(i)        printf("%lld\n",i)
#define     printt(i,j)     printf("%lld %lld\n",i,j)
#define     loop(i,n) 	    for(int i = 0 ; i <n ; i++)
#define     loopp(i,n) 	    for(int i = 1 ; i <n ; i++)
#define     rep(i,n)        for(int i=n-1;i>=0;i--)
#define     rev(v)          reverse(v.begin(),v.end())
#define     reset(a,b)      memset(a,b,sizeof(a))
#define 	vect 	        vector<int>
#define 	vec_it 	        vector<int>::reverse_iterator vi
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
#define 	set_it 	        set<int>::reverse_iterator si
#define     map_it          map<int,int> :: reverse_iterator mi
#define     setp(x)         fixed<<setprecision(x)
#define     digit(n)        floor(log10(n)+1)
#define 	yes 	        cout<<"YES"<<endl
#define 	no 	            cout<<"NO"<<endl
#define 	ff 	            first
#define 	ss 	            second
#define     mx              INT_MAX
#define     lmx             LLONG_MAX
#define     mn              INT_MIN
#define     lmn             LLONG_MIN
#define     inf             0x3f3f3f3f
#define     inff            10e18
#define     GCD             __gcd(a,b)
#define     LCM             (a/GCD)*b
#define     ub              upper_bound
#define     lb              lower_bound
template <typename T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {return a*(b/gcd(a,b));}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // 1 2 3
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> reverse_ordered_set; // 3 2 1
int modulo (int a, int b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }

#define lx 100002
int store[lx];

int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+= store[i];
        i-=(i&-i);
    }
    return sum;
}

void bit(int i,int val,int n)
{
    while(i<=n)
    {
        store[i]+=val;
        i+=(i&-i); // ekhane i ke 2's complement korle -i paowa jay i+ =i AND -i tahole next index pabo jetay value ta add
                   // hobe
    }
}

void solve()
{
   // freopen ("(input).txt" , "r",  stdin) ;
    string st,stt;
    int low=0,high=0;
    int l,r; char ch;
    int n,k,t,x,y,z,d=0,cnt=0,temp=0,sum=0,f=0,flag=0;
    cin>>n ; vect v(n+1) ; sett s ; mapp m,mm ; pairr p ;
    reset(store,0);
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        bit(i,x,n);
    }
    //Ekhon jodi bole 4 theke 9 porjonto sum ber korte tahole
    d=query(3);
    f=query(9);
    cout<<f-d<<endl; ///ans print
    //jodi bole 3no index a 5 add korte
    bit(3,5,n); ///etai update

}

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
