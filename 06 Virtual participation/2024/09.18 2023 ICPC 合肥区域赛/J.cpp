#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[300010];
int n,m,x,y,w,ans;
int d1[300010],dn[300010];
vector<pair<pair<int,int>,int> >p;
void solve()
{
	ans=2e9+7;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
		p.push_back({{x,y},w});
	}
	
	
	priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	
	vector<int>vt(n+1);
	
	for(int i=1;i<=n;i++) d1[i]=1e9+7,vt[i]=0;
	
	d1[1]=0;
	q.push({0,1});
	
	while(!q.empty())
	{
		int u=q.top().second;
		int w=q.top().first;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		
		for(auto v1:g[u])
		{
			int v=v1.first;
			int nw=max(w,v1.second);
			
			if(nw<d1[v])
			{
				d1[v]=nw;
				q.push({d1[v],v});
			}
		}
	}
	
	for(int i=1;i<=n;i++) dn[i]=1e9+7,vt[i]=0;
	dn[n]=0;	
	q.push({0,n});
	
	while(!q.empty())
	{
		int u=q.top().second;
		int w=q.top().first;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		
		for(auto v1:g[u])
		{
			int v=v1.first;
			int nw=max(w,v1.second);
			
			
			if(nw<dn[v])
			{
				dn[v]=nw;
				q.push({dn[v],v});
			}
		}
	}
	
	
	for(auto i:p)
	{
		int u,v,w;
		u=i.first.first;
		v=i.first.second;
		w=i.second;
		if(d1[u]<=w&&dn[v]<=w)
		{
			ans=min(ans,w+max(d1[u],dn[v]));
		}
		if(d1[v]<=w&&dn[u]<=w)
		{
			ans=min(ans,w+max(d1[v],dn[u]));
		}
	}

	cout<<ans<<"\n";

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
