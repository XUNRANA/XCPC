#include <bits/stdc++.h>
using namespace std;
int n,a,b,u,v,fu,fv,fx;
vector<int>g[200010];
int fa[200010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	fx=0;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) g[i].clear(),fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		fu=find(u);
		fv=find(v);
		if(fu==fv)
		{
			if(find(a)==find(b)) fx=1;
		}
		else fa[fu]=fv;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(fx==1) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
