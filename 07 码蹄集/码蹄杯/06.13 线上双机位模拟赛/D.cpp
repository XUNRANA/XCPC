#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    cout<<max(n,m)*max(n,m)-n*m<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}