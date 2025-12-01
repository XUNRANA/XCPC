#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[51];
void solve()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,a[i]-a[i-1]);
    ans=max(ans,2*(x-a[n]));
    cout<<ans<<"\n";
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