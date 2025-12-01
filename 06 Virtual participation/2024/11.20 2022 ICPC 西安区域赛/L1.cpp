#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int n,p[N],fa[N];
vector<int>g[N];
int in[N],len[N],son[N];
vector<int>lp;
void dfs1(int x)//ÖØÁ´ÆÊ·Ö 
{
	for(auto y:g[x])
	{
		dfs1(y);
		if(len[y]>len[son[x]]) son[x]=y;
	}
	len[x]=len[son[x]]+1;
}
void dfs2(int x,int l)
{
	if(!son[x]) lp.push_back(l);
	else
	{
		dfs2(son[x],l+1);
		for(auto y:g[x])
		if(y!=son[x]) dfs2(y,1);
	}
}
void solve()
{
	cin>>n;
	lp.clear();
	for(int i=1;i<=n;i++) son[i]=len[i]=0,g[i].clear();
	for(int i=2;i<=n;i++) 
	{
		int x;
		cin>>x;
		g[x].push_back(i);
	}
	
	dfs1(1);
	dfs2(1,1);
	
	sort(lp.begin(),lp.end(),greater<int>());
	int p=lp.size(),ans=p;
	for(int i=0;i<p;i++) ans=min(ans,lp[i]+i);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
