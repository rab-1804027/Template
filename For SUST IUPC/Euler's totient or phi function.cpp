/// Blog Link: https://forthright48.com/euler-totient-or-phi-function
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define lx 10000005
vector<int>primes;
bool mark[lx];

int EulerPhi(int n)
{
    int res=n;
    int sqrtn=sqrt(n);
    for(int i=0;i<primes.size()&&primes[i]<=sqrtn;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
                n/=primes[i];
            sqrtn=sqrt(n);
            res/=primes[i];
            res*=(primes[i]-1);
        }
    }
    if(n!=1)
        res/=(n),res*=(n-1);
    return res;
}

void siv()
{
    for(int i=4;i<lx;i+=2)
        mark[i]=1;
    for(int i=3;i*i<lx;i+=2)
    {
        if(mark[i]==0)
        {
            for(int j=i+i;j<lx;j+=i)
                mark[j]=1;

        }
    }
    for(int i=2;i<lx;i++)
    {
        if(mark[i]==0)
            primes.pb(i);
    }
}

void solve()
{
    int n;
    cin>>n;
    /// Euler phi diye n er sathe jotogula number(upto n) coprime ta count kora jabe)
    cout<<EulerPhi(n)<<endl;
}

main()
{
    siv();
    int t;
    cin>>t;
    while(t--)
        solve();
}
