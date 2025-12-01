#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;
    int tb=b;
    while(__gcd(a,b)!=1)
    {
        b/=__gcd(a,b);
    }
    if(__gcd(b,a)!=1||__gcd(b,tb)<=1) cout<<"-1\n";
    else
    {
        cout<<b<<"\n";
    }
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}