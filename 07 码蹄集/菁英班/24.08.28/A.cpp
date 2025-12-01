#include <bits/stdc++.h>
using namespace std;
int n,k,u,v,dis[110],vt[110];
vector<int>g[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>k;
		while(k--)
		{
			cin>>v;
			g[u].push_back(v);
		}
	}
	for(int i=1;i<=n;i++) dis[i]=1e9;
	queue<int>q;
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v:g[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++) if(dis[i]==1e9) cout<<i<<" -1\n";
	else cout<<i<<" "<<dis[i]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
