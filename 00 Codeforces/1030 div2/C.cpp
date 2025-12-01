#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>c(60,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<60;j++) if(x>>j&1) ans++;
        else c[j]++;
    }
    
    for(int i=0;i<60;i++)
    {
        int t=min(k/(1ll<<i),c[i]);
        k-=t*(1ll<<i);
        ans+=t;
    }
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