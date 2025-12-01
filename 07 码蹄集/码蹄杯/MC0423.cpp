#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a,b;
    cin>>a>>b;
    if(!(a&1)||!(b&1)) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}