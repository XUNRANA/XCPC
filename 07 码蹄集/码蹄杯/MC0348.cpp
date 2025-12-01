#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

multiset<int>g[100010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    queue<int>q;
    for(int i=1;i<=n;i++) if(g[i].size()==1) q.push(i);
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            g[v].erase(g[v].find(u));
            if(g[v].size()==1) q.push(v);
        }
        g[u].clear();
    }
    for(int i=n;i>=1;i--) if(g[i].size()==2) cout<<i<<" ";
    cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
