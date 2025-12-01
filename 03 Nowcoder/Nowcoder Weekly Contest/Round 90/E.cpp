#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,in[200010];
int a[200010];
void solve() 
{
    cin>>n;
    int mi=1e9;
    for(int i=1;i<=n;i++) cin>>a[i],mi=min(mi,a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        in[u]++;
        in[v]++;
    }
    int ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++) if(in[i]==1) ans+=a[i],cnt++;
    if(cnt&1) ans+=mi;
    cout<<ans<<"\n";
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