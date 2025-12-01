#include <bits/stdc++.h>
using namespace std;
#define int long long
int fa[200010];
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	fa[fu]=fv;
}
vector<pair<int,int> >g[20];
int b[400010];
void solve()
{
	int n,m,a,d,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=10;i++) g[i].clear();
	for(int i=1;i<=m;i++)
	{
		cin>>a>>d>>k;
		g[d].push_back({a,k});
	} 
	
	for(int i=1;i<=10;i++)
	{
		sort(g[i].begin(),g[i].end());
		for(int j=1;j<=n;j++) b[j]=0;
		for(auto j:g[i])
		{
			a=j.first;
			k=j.second;
			b[a]++;
			b[a+i*k]--;
		}
		for(int j=i+1;j<=n;j++) b[j]+=b[j-i];
		int p=0;
		for(int j=1;j<=n;j++) if(b[j]) merge(j,j+i);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) if(find(i)==i) ans++;
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
