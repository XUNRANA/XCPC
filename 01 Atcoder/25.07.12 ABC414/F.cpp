#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int>g[200010];
int n,k,u,v;
int dep[200010];
void dfs(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=2;i<=n;i++)
    if(dep[i]%k==0) cout<<dep[i]/k<<" ";
    else cout<<"-1 ";
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}