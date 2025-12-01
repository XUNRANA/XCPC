#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,fa[N],a[N],vis[N],de[N],sz[N],ans,id; 
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
pair<int,int>E[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		sz[i]=1;
		vis[i]=0;
		de[i]=0;
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		if(a[u]>a[v]) swap(u,v);
		if(a[v]>=a[u]*2+1) vis[i]=1,swap(u,v);
		else if(a[u]>=a[v]*2+1) vis[i]=1;
		else
		{
			int x=find(u),y=find(v);
			fa[x]=y;
			sz[y]+=sz[x];
		}
		E[i].first=u;
		E[i].second=v;
	}
	for(int i=1;i<n;i++)
	{
		if(vis[i]) de[find(E[i].first)]++;
	}
	id=0;
	for(int i=1;i<=n;i++)
	if(i==find(i)&&de[i]==0)
	{
		if(!id) id=i;
		else 
		{
			id=-1;
			break;
		}
	}
	if(id==-1) ans=0;
	else ans=sz[id];
	cout<<ans<<'\n';
	 
}
signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--) solve();
}
