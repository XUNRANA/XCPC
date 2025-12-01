#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y;
int w[10010],in[10010],res[10010];
vector<int>g[10010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		w[x]=y;
		while(1)
		{
			cin>>y;
			if(y==0) break;
			g[y].push_back(x);
			in[x]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++) 
	if(!in[i]) 
	{
		q.push(i);
		res[i]=w[i];
	}
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			res[v]=max(res[v],res[u]+w[v]);
			in[v]--;
			if(!in[v]) q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(res[i],ans);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}