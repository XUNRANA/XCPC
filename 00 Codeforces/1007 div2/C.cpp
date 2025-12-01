#include <bits/stdc++.h>
using namespace std;
#define int long long
int dep[100010];
vector<int>g[100010];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void solve()
{
    int n,st,en,u,v;
    cin>>n>>st>>en;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[en]=0;
    dfs(en,0);
    vector<pair<int,int>>a;
    for(int i=1;i<=n;i++) a.push_back({dep[i],i});
    sort(a.begin(),a.end(),greater<pair<int,int>>());
    for(auto i:a) cout<<i.second<<" ";
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

