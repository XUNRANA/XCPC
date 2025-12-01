#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,m,k;
int a[210],b[210],c[210];
void solve() 
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=k;i++) cin>>c[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int j1=1;j1<=k;j1++)
            {
                ans=max(ans,a[i]*b[j]%c[j1]);
            }
        }
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