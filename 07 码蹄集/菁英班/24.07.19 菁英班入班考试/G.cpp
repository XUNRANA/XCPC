#include <bits/stdc++.h>
using namespace std;
int n,m,u,v;
map<int,vector<int>>mp;
int vt[510];
void dfs(int u,int fa)
{
    vt[u]=1;
    for(auto v:mp[u])
    {
        if(vt[v]||v==fa) continue;
        dfs(v,u);
    }
}
void solve()
{
	cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        mp[u].push_back(v);
    }
    dfs(1,0);
    if(vt[n]) cout<<"Yes\n";
    else cout<<"No\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

