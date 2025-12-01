#include <bits/stdc++.h>
using namespace std;


int c[210];
vector<pair<int,int>>g[210];
int d[210];
int vt[210];
int cnt[210];
int mx[210];
int pre[210];
string str[210];
int c1[210];
int n,m;
void dij(int s)
{
	for(int i=1;i<=n;i++) d[i]=1e9;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	d[s]=0;
	q.push({d[s],s});
	c1[s]=1;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			if(d[v]>d[u]+w)
			{
				c1[v]=c1[u];
				d[v]=d[u]+w;
				cnt[v]=cnt[u]+1;
				mx[v]=mx[u]+c[v];
				q.push({d[v],v});
				pre[v]=u;
			}
			else if(d[v]==d[u]+w)
			{
				c1[v]+=c1[u];
				if(cnt[v]<cnt[u]+1) 
				{
					cnt[v]=cnt[u]+1;
					mx[v]=mx[u]+c[v];
					q.push({d[v],v});
					pre[v]=u;
				}
				else if(cnt[v]==cnt[u]+1)
				{
					if(mx[v]<mx[u]+c[v])
					{
						mx[v]=mx[u]+c[v];
						q.push({d[v],v});
						pre[v]=u;
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<i<<" "<<c1[i]<<"\n";
}
void solve()
{
	
	string a,b; 
	cin>>n>>m>>a>>b;
	map<string,int>mp;
	for(int i=1;i<n;i++)
	{
		string s;
		cin>>s>>c[i];
		str[i]=s;
		mp[s]=i;
	}
	str[n]=a;
	mp[a]=n;
	for(int i=1;i<=m;i++)
	{
		string s,t;
		int w;
		cin>>s>>t>>w;
		g[mp[s]].push_back({mp[t],w});
		g[mp[t]].push_back({mp[s],w});
	}
	int aa=mp[a];
	int bb=mp[b];
	dij(aa);
	vector<int>p;
	while(pre[bb]!=aa) 
	{
		p.push_back(bb);
//		cout<<bb<<" ";
		bb=pre[bb];
	}
	p.push_back(bb);
	p.push_back(aa);
	for(int i=0;i<p.size()/2;i++) swap(p[i],p[p.size()-1-i]);
	for(int i=0;i<p.size();i++)
	{
		if(i) cout<<"->";
		cout<<str[p[i]];
	}
	cout<<"\n";
//	cout<<bb<<" "<<aa<<"\n";
	bb=mp[b];
	cout<<c1[bb]<<" "<<d[bb]<<" "<<mx[bb]<<"\n";
//	cout<<aa<<" "<<bb<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
