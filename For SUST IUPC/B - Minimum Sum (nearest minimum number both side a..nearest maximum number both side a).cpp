///Bismillahir Rahmanir Rahim
// https://atcoder.jp/contests/agc005/tasks/agc005_b?lang=en
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
typedef tree<pairr, null_type, less<pairr>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int cnt=0,temp=0,sum=0,ans=0;
    int n;
    cin>>n;
    vect a(n+5);
    int l[n+5],r[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[i]=1,r[i]=n;
    }
    ordered_set pre,suf;
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            if(pre.size()==0)
                break;
            pairr p=*pre.rbegin();
            if(p.ff>a[i])
                r[p.ss]=i-1;
            else
                break;
            pre.erase(p);
        }
        pre.insert({a[i],i});
    }
    for(int i=n;i>0;i--)
    {
        while(1)
        {
            if(suf.size()==0)
                break;
            pairr p=*suf.rbegin();
            if(p.ff>a[i])
                l[p.ss]=i+1;
            else
                break;
            suf.erase(p);
        }
        suf.insert({a[i],i});
    }
    for(int i=1;i<=n;i++)
    {
        ans+=((r[i]-i+1)+(r[i]-i+1)*(i-l[i]))*a[i];

    }
    cout<<ans<<endl;
    /*
    vect a(n+1);
    for(int i=0;i<=n+1;i++)
        presum[i]=0,sufsum[i]=0,l[i]=1,r[i]=n;
    ordered_set pre,suf;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        presum[i]=sum;
        if(a[i]>0)
        {
            while(1)
            {
                if(pre.size()==0)
                    break;
                pairr p=*pre.begin();
                if(p.ff<a[i])
                    r[p.ss]=i-1;
                else
                    break;
                pre.erase(p);
            }
        }
        pre.insert({a[i],i});
    }
    for(int i=n;i>0;i--)
    {
        cnt+=a[i];
        sufsum[i]=cnt;
        if(a[i]>0)
        {
            while(1)
            {
                if(suf.size()==0)
                    break;
                pairr p=*suf.begin();
                if(p.ff<a[i])
                    l[p.ss]=i+1;
                else
                    break;
                suf.erase(p);
            }
        }
        suf.insert({a[i],i});
    }
    */

}

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
