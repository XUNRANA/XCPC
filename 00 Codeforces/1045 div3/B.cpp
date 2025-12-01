#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=a[2]-a[1];
    for(int i=1;i<=n;i+=2) ans=max(ans,a[i+1]-a[i]);
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}