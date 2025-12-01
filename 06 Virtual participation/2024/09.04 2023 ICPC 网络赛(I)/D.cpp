#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v,ans,fa[1000010],sz[1000010],d[1000010];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,d[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		d[u]++;
		d[v]++;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		if(fu>fv)
		{
			sz[fu]+=sz[fv];
			fa[fv]=fu;
		}
		else
		{
			sz[fv]+=sz[fu];
			fa[fu]=fv;
		}
	}
	for(int i=1;i<=n;i++) ans+=sz[find(i)]-d[i]-1;
	ans/=2;
	set<int>s;
	for(int i=1;i<=n;i++) s.insert(find(i));
	int mi1=1e9,mi2=1e9;
	for(auto i:s)
	{
		if(sz[i]<mi1)
		{
			mi2=mi1;
			mi1=sz[i];
		}
		else if(sz[i]<mi2)
		{
			mi2=sz[i];
		}
	}
	
	if(!ans) cout<<mi1*mi2<<"\n";
	else cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
