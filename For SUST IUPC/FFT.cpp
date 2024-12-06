/// Bismillahir Rahmanir Rahim
/// https://www.spoj.com/problems/POLYMUL/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;

#define     FAST            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define     int             long long
#define     pb              push_back
#define     endl            '\n'
#define     pi              2*acos(0.0)
#define     scan(i)         scanf("%lld",&i)
#define     scann(i,j)      scanf("lld",&i,&j)
#define     print(i)        printf("%lld\n",i)
#define     printt(i,j)     printf("%lld %lld\n",i,j)
#define     loop(i,n)       for(int i = 0 ; i <n ; i++)
#define     rev(v)          reverse(v.begin(),v.end())
#define     reset(a,b)      memset(a,b,sizeof(a))
#define     vect            vector<int>
#define     sorta(v)        sort(v.begin(),v.end())
#define     sortd(v)        sort(v.begin(),v.end(),greater<>())
#define     sorted(v)       is_sorted(v.begin(),v.end())
#define     mnv(v)          *min_element(v.begin(),v.end())
#define     mxv(v)          *max_element(v.begin(),v.end())
#define     countv(v,a)     count(v.begin(),v.end(),a)
#define     vplusa(v,a)     v.insert(v.end(),a.begin(),a.end())
#define     mapp            map<int,int>
#define     rmap            map<int,int,greater<>>m
#define     pairr           pair<int,int>
#define     sett            set<int>
#define     rset            set<int,greater<>>s
#define     setp(x)         fixed<<setprecision(x)
#define     digit(n)        floor(log10(n)+1)
#define     bdigit(n)       floor(log2(n)+1)
#define     yes             cout<<"YES"<<endl
#define     no              cout<<"NO"<<endl
#define     ff              first
#define     ss              second
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
template<class T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ld = long double;

struct cplx {
  ld a, b;
  cplx(ld a=0, ld b=0):a(a), b(b) {}
  const cplx operator + (const cplx &z) const { return cplx(a+z.a, b+z.b); }
  const cplx operator - (const cplx &z) const { return cplx(a-z.a, b-z.b); }
  const cplx operator * (const cplx &z) const { return cplx(a*z.a-b*z.b, a*z.b+b*z.a); }
  const cplx operator / (const ld &k) const { return cplx(a/k, b/k); }
};

const ld PI=acos(-1);
vector<int> rev;

void pre(int sz){
  if(rev.size()==sz)  return ;
  rev.resize(sz);
  rev[0]=0;
  int lg_n = __builtin_ctz(sz);
  for (int i = 1; i < sz; ++i)  rev[i] = (rev[i>>1] >> 1) | ((i&1)<<(lg_n-1));
}

void fft(vector<cplx> &a, bool inv){
  int n = a.size();

  for (int i = 1; i < n-1; ++i) if(i<rev[i])  swap(a[i], a[rev[i]]);

  for (int len = 2; len <= n; len <<= 1){
    ld t = 2*PI/len*(inv? -1: 1);
    cplx wlen = {cosl(t), sinl(t)};
    for (int st = 0; st < n; st += len){
      cplx w(1);
      for (int i = 0; i < len/2; ++i){
        cplx ev = a[st+i];
        cplx od = a[st+i+len/2]*w;
        a[st+i] = ev+od;
        a[st+i+len/2] = ev-od;
        w = w*wlen;
      }
    }
  }

  if(inv){
    for(cplx &z: a){
      z = z/n;
    }
  }
}

vector<int> mul(vector<int> &a, vector<int> &b){
  int n = a.size(), m = b.size(), sz = 1;
  while (sz < n+m-1)  sz <<= 1;
  vector<cplx> x(sz), y(sz), z(sz);
  for (int i = 0; i < sz; ++i){
    x[i] = cplx(i<n? a[i]: 0, 0);
    y[i] = cplx(i<m? b[i]: 0, 0);
  }
  pre(sz);
  fft(x, 0);
  fft(y, 0);
  for (int i = 0; i < sz; ++i){
    z[i] = x[i] * y[i];
  }
  fft(z, 1);
  vector<int> c(n+m-1);
  for (int i = 0; i < n+m-1; ++i){
    c[i] = round(z[i].a);
  }
  return c;
}

void solve(int tc)
{
    int cnt=0,temp=0,sum=0,ans=0;
    int n;
    cin>>n;
    vect a(n+1),b(n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) cin>>b[i];
    vect vec=mul(a,b);
    for(int i=0;i<=n*2;i++)
        cout<<vec[i]<< " ";
    cout<<endl;

}

int32_t main()
{
    FAST;
    int t,tc=0;
    cin>>t;
    while(t--)
        solve(++tc);
}

