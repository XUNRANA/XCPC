#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
vector<int>g[N];
int busy[N],vt[N];
void solve()
{
	int n,m,k,u,v;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) busy[i]=vt[i]=0,g[i].clear();
	for(int i=1;i<=k;i++)
	{
		int u;
		cin>>u;
		busy[u]=1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(!busy[i])
		{
			q.push(i);
			vt[i]=1;
			break;
		}
	}
	vector<vector<int>>ans;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		
		vector<int>join;
		
		for(auto v:g[u])
		{
			if(vt[v]) continue;
			join.push_back(v);
			if(!busy[v]) q.push(v);
			vt[v]=1;
		}
		if(join.size()==0) continue;
		vector<int>a;
		a.push_back(u);
		a.push_back(join.size());
		for(auto v:join) a.push_back(v);
		ans.push_back(a);
	}
	for(int i=1;i<=n;i++) 
	if(!vt[i])
	{
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
	cout<<ans.size()<<"\n";
	for(auto i:ans) 
	{
		for(auto j:i) cout<<j<<" ";
		cout<<"\n";
	}
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
