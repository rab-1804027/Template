#include<bits/stdc++.h>
using namespace std;

void z_algo(string st)
{
    int n=st.size();
    vector<int> z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&st[z[i]]==st[i+z[i]])
            z[i]++;
        if(i+z[i]-1>r)
            l=i,r=i+z[i]-1;
    }
    for(auto i:z) cout<<i<< " ";
    /*
    ei function er kaj holo jodi ekta string abcdabc hoy tahole proti positon
    theke koyta prefix oi position theke suffix
    er soman hoy ta oi position a dibe
    like
    abcdabc
pos=0123456
    0000300 er mane 4th positon theke 3 ta mane abc prefix and abc suffix
    aaaaa
    04321
    aabaabcaabaabaab
    0103100610610310
    */

}

main()
{
    string st;
    cin>>st;
    z_algo(st);
}
