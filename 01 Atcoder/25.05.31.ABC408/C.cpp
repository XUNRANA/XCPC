#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    int ans=m;
    for(int i=1;i<=n;i++) ans=min(ans,a[i]);
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