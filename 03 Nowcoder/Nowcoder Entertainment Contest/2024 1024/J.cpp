#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,fa[1010];
int find(int x)
{
	return x==fa[x]? x:find(fa[x]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q.push({w,u,v});
	}
	int ans=0;
	vector<int>res;
	res.push_back(0);
	while(!q.empty())
	{
		int w=q.top()[0];
		int u=q.top()[1];
		int v=q.top()[2];
		q.pop();
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		ans+=w;
		res.push_back(ans);
	}
	for(int i=res.size()-1;i>=0;i--) cout<<res[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
// 	cin>>T;
	while(T--) solve();
}
