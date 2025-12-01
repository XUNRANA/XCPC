#include <bits/stdc++.h>
using namespace std;
int d[1010][1010];

int n,m;
vector<array<int,3>>g[1010];
int vt[1010];
void dij(int s,int d[])
{
	for(int i=1;i<=n;i++) d[i]=1e9,vt[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,s});
	d[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;
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
}
int d1[1010];
int d2[1010];
int pre[1010];

void dij1(int s,int t)
{
	if(s==t) 
	{
		cout<<s<<"\n";
		cout<<"0 0\n";
		return ;
	}
	for(int i=1;i<=n;i++) d1[i]=d2[i]=1e9,vt[i]=pre[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,s});
	d1[s]=0;
	d2[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;

		for(auto v:g[u])
		{
			if(d1[v[0]]>d1[u]+v[1])
			{
				pre[v[0]]=u;
				d1[v[0]]=d1[u]+v[1];
				d2[v[0]]=d2[u]+v[2];
				q.push({d1[v[0]],v[0]});
			}
			else if(d1[v[0]]==d1[u]+v[1])
			{
				if(d2[v[0]]<d2[u]+v[2])
				{
					pre[v[0]]=u;
					d2[v[0]]=d2[u]+v[2];
					q.push({d1[v[0]],v[0]});
				}
			}
		}
	}
	vector<int>path;
	int ans1=d1[t];
	int ans2=d2[t];
	while(pre[t]!=s)
	{
		path.push_back(t);
		t=pre[t];
	}
	path.push_back(t);
	path.push_back(s);
	for(int i=0;i<path.size()/2;i++) swap(path[i],path[path.size()-1-i]);
	int f=0;
	for(auto i:path) 
	{
		if(f) cout<<"->";
		cout<<i;
		f=1;
	}
	cout<<"\n";
	cout<<ans1<<" "<<ans2<<"\n";
}
int k;
int a[1010];
void solve()
{
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w1,w2;
		cin>>u>>v>>w1>>w2;
		g[u].push_back({v,w1,w2});
		g[v].push_back({u,w1,w2});
	} 
	cin>>k;
	for(int i=1;i<=k;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++) dij(i,d[i]);
	int idx=1;
	int mx=1e9;
	for(int i=1;i<=n;i++) 
	{
		int mx1=0;
		for(int j=1;j<=n;j++) mx1=max(mx1,d[i][j]);
		if(mx1<mx)
		{
			mx=mx1;
			idx=i;
		}
	}
	cout<<idx<<"\n";
	for(int i=1;i<=k;i++)
	{
		dij1(idx,a[i]);
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
