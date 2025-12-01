#include <bits/stdc++.h>
using namespace std;
#define N 200010
vector<int>g[N];
int a[N],d0[N],d1[N],v0[N],v1[N];
int dis1[N],dis0[N],vt0[N],vt1[N];
void solve()
{
	int n,m,d,k;
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=m;i++) 
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>k;
	for(int i=1;i<=k;i++) cin>>a[i];
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	for(int i=1;i<=n;i++) d0[i]=d1[i]=1e9,v0[i]=v1[i]=0;
	
	for(int i=1;i<=k;i++)
	{
		int u=a[i];
		d0[u]=2;
		q.push({2,u});
		for(auto v:g[u])
		{
			d1[v]=1;
			q.push({1,v});
		}
	}
	
	while(!q.empty())
	{
		int u=q.top().second;
		int t=q.top().first;
		q.pop();
		if(t+1>d) continue;
		if(t%2==0)
		{
			if(v0[u]) continue;
			v0[u]=1;
			for(auto v:g[u])
			{
				if(d1[v]>t+1)
				{
					d1[v]=t+1;
					q.push({d1[v],v});
				}
			}
		}
		else
		{
			if(v1[u]) continue;
			v1[u]=1;
			for(auto v:g[u])
			{		
				if(d0[v]>t+1)
				{
					d0[v]=t+1;
					q.push({d0[v],v});
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++) dis1[i]=dis0[i]=1e9,vt0[i]=vt1[i]=0;
	q.push({0,1});
	dis0[1]=0;
	
	while(!q.empty())
	{
		int u=q.top().second;
		int t=q.top().first;
		q.pop();
		if(t&1)
		{
			if(vt1[u]) continue;
			vt1[u]=1;
		}
		else
		{
			if(vt0[u]) continue;
			vt0[u]=1;
		}
		
		if(u==n) break;
		for(auto v:g[u])
		{
			if(t&1)
			{
				if(d0[v]>t+1&&dis0[v]>t+1)
				{
					dis0[v]=t+1;
					q.push({t+1,v});
				}
			}
			else
			{
				if(d1[v]>t+1&&dis1[v]>t+1)
				{
					dis1[v]=t+1;
					q.push({t+1,v});
				}
			}
		}
	}

	if(!vt0[n]&&!vt1[n])
	{
		cout<<"-1\n";
		return ;
	} 
	
//	cout<<vt[n]<<"\n";
	
	int u=n;
	int t=min(dis1[n],dis0[n]);
	cout<<t<<"\n";
	vector<int>ans;
	ans.push_back(n);
	while(t)
	{
		for(auto v:g[u])
		{
			if(t&1)
			{	
				if(dis0[v]==t-1)
				{
					ans.push_back(v);
					u=v;
					t--;
					break;
				}
			}
			else
			{
				if(dis1[v]==t-1)
				{
					ans.push_back(v);
					u=v;
					t--;
					break;
				}
			}
		}
	}
	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
