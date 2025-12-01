#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,k,cnt[N],sz[N],s[N],c[N],ans[N];
vector<int>g[N];
void dfs1(int u,int fa)
{
	sz[u]=1;
	for(auto v:g[u])
	{ 
		if(v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(!s[u]||sz[s[u]]<sz[v]) s[u]=v;//重儿子 
	}
}
int dfs2(int u,int fa,int isson,int keep)
{
	if(keep)//轻儿子，保留答案 
	{
		for(auto v:g[u])
		{
			if(v==fa||v==s[u]) continue;
			dfs2(v,u,0,1);
		}
	}
	int t=0;
	if(!keep&&s[u]) t+=dfs2(s[u],u,1,0);
	else if(s[u]) t+=dfs2(s[u],u,1,1);
	for(auto v:g[u])//轻儿子cnt 
	{
		if(v==fa||v==s[u]) continue;
		t+=dfs2(v,u,0,0);
	}
	if(!cnt[c[u]]) t++;
	cnt[c[u]]++;
	if(keep) ans[u]=t;
	if(keep&&!isson) memset(cnt,0,sizeof(cnt));
	return t;
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs1(1,0);
	dfs2(1,0,1,1);
	cin>>m;
	while(m--)
	{
		cin>>k;
		cout<<ans[k]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
