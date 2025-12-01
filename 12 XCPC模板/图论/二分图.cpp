#include  <bits/stdc++.h>
using namespace std;
#define N 1010
int vt[N],mch[N];
vector<int>g[N];
bool dfs(int u,int t)
{
	if(vt[u]==t) return 0;
	vt[u]=t;
	for(auto v:g[u]) 
	if(mch[v]==0||dfs(mch[v],t))
	{
		mch[v]=u;
		return 1;
	}
	return 0;
}
void solve()
{
	int n,m,e,u,v;
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(dfs(i,i)) ans++;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
