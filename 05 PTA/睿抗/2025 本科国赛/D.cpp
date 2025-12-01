#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[1010];
int d[1010];
int vt[1010];
vector<array<int,2>>g[1010];
int fa[1010];

int u[30010];
int v[30010];
int t[30010];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	fa[fu]=fv;
}
int s1,t1;
bool ck(int x)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(c[u[i]]<=x&&c[v[i]]<=x)
		merge(u[i],v[i]);
	}
	return find(s1)==find(t1);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>t[i];
	cin>>s1>>t1;
	c[s1]=c[t1]=0;
	int l=0,r=1e5;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)) r=mid-1;
		else l=mid+1;
	}
	
	
	for(int i=1;i<=m;i++)
	{
		if(c[u[i]]<=l&&c[v[i]]<=l)
		{
			g[u[i]].push_back({v[i],t[i]});
			g[v[i]].push_back({u[i],t[i]});
		}
	}
	
	for(int i=1;i<=n;i++) d[i]=1e9;
	d[s1]=0;
	
	priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
	q.push({0,s1});
	while(!q.empty())
	{
		int u=q.top()[1];
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v:g[u])
		{
			if(d[v[0]]>d[u]+v[1])
			{
				d[v[0]]=d[u]+v[1];
				q.push({d[v[0]],v[0]});
			}	
		}	
	}
	
	cout<<l<<" "<<d[t1]<<"\n";
		
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
