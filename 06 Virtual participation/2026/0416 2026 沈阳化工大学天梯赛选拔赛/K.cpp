#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    int ans=a[1]*a[2*m];
    for(int i=1;i<=m;i++)
    {
        ans=min(ans,a[i]*a[2*m-i+1]);
        // cout<<a[i]*a[2*m-i+1]<<"\n";
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

