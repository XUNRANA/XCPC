#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v,w[100010],in[100010],ot[100010];
vector<int>g[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		ot[u]++;
		in[v]++;
	}
	priority_queue<int,vector<int>,greater<int>>q;
	vector<int>res,ans;
	for(int i=1;i<=n;i++) 
	{
		if(!ot[i]) ans.push_back(i);
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
        res.push_back(u);
		for(auto v:g[u])
		{
			w[v]+=w[u];
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}
	for(auto i:res) cout<<i<<" ";
	cout<<"\n";
	for(auto i:ans) cout<<w[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
