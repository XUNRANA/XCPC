#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b,n;
    cin>>a>>b>>n;
    n-=b/2*3;
    if(n<0) n+=3;
    if(n<=a) cout<<"YES\n";
    else cout<<"NO\n";
}
            
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
