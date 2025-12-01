#include <bits/stdc++.h>
using namespace std;
#define int long long

int x[2010];
int y[2010];

void solve() 
{
    int n;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    int mx=-1e9;
    int mi=1e9;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,x[i]);
        mi=min(mi,x[i]);
        for(int j=i+1;j<=n;j++)
        {
            ans+=abs(y[i]-y[j]);
        }
    }
    cout<<ans<<"\n";
}

signed  main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
