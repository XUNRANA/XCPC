#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[200010][31];
vector<array<int,2>>g[200010];
void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
    }

    for(int j=1;j<=n;j++) dp[j][0]=1;
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=n;j++)
        for(auto v:g[j])
        {
            dp[j][i]=max(dp[j][i],dp[v[0]][i-1]*v[1]);
        }
    }
    while(q--)
    {
        int p,x;
        cin>>p>>x;
        for(int i=1;i<=30;i++)
        if(x/dp[p][i]==0)
        {
            cout<<i<<"\n";
            break;
        }
    }
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
