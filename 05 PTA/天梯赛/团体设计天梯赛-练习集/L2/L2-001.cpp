#include <bits/stdc++.h>
using namespace std;


int n,m,s,d,mi;
int a[5100],dis[5100],vt[5100],cnt[5100],mx[5100],pre[5100];
vector<pair<int,int>>g[5100];

void dij(int s,int d)
{
	for(int i=1;i<=n;i++) dis[i]=1e9,vt[i]=0;
	dis[s]=0;
	cnt[s]=1;
	mx[s]=a[s];
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int cost=v1.second;
			if(dis[u]+cost<dis[v])
			{
			
				dis[v]=dis[u]+cost;
				
				q.push({dis[v],v});
				
				cnt[v]=cnt[u];
				pre[v]=u;
				mx[v]=mx[u]+a[v];
			}
			else if(dis[u]+cost==dis[v])
			{
				cnt[v]+=cnt[u];
				
				if(mx[u]+a[v]>mx[v]) pre[v]=u;
				
				mx[v]=max(mx[u]+a[v],mx[v]);
			}
		}
	}
}
 
void solve()
{
	cin>>n>>m>>s>>d;
	s++;
	d++;
	for(int i=1;i<=n;i++) cin>>a[i];	
	for(int i=1;i<=m;i++)
	{
		int x,y,l;
		cin>>x>>y>>l;
		x++;
		y++;
		g[x].push_back({y,l});
		g[y].push_back({x,l});
	}
	dij(s,d);
	cout<<cnt[d]<<" "<<mx[d]<<"\n";
	vector<int>path;
	path.push_back(d);
	while(pre[d]!=s) 
	{
		path.push_back(pre[d]);
		d=pre[d];
	}
	path.push_back(s);
	int f=0;
	for(int i=path.size()-1;i>=0;i--)
	{
		if(f) cout<<" ";
		cout<<path[i]-1;
		f=1;
	} 
} 
 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}



/*
#include <bits/stdc++.h>
using namespace std;


int n,m,s,d,mi;
int a[5100],vt[5100];
vector<pair<int,int>>g[5100];
vector<int>path;
vector<vector<int>>res;
void dfs(int u,int fa,int c,int c1)
{
	if(u==d)
	{
		if(c<mi)
		{
			mi=c;
			res.clear();
			res.push_back(path);
		}
		else if(c==mi) res.push_back(path);
		return ;
	}
	for(auto v1:g[u])
	{
		int v=v1.first;
		int l=v1.second;
		if(v==fa||vt[v]) continue;
		
		vt[v]=1;
		path.push_back(v);
		dfs(v,u,c+l,c1+a[v]);
		path.pop_back();
		vt[v]=0;
	}
}
void solve()
{
	cin>>n>>m>>s>>d;
	s++;
	d++;
	for(int i=1;i<=n;i++) cin>>a[i];	
	for(int i=1;i<=m;i++)
	{
		int x,y,l;
		cin>>x>>y>>l;
		x++;
		y++;
		g[x].push_back({y,l});
		g[y].push_back({x,l});
	}
	
	mi=1e9;
	
	path.push_back(s);
	vt[s]=1;
	dfs(s,-1,0,a[s]);
	vt[s]=0;
	
	cout<<res.size()<<" ";
	int mx=0;
	for(auto i:res)
	{
		int s=0;
		for(auto j:i) s+=a[j];
		mx=max(mx,s);
	}
	cout<<mx<<"\n";
	for(auto i:res)
	{
		int s=0;
		for(auto j:i) s+=a[j];
		if(s==mx)
		{
			int f=0;
			for(auto j:i)
			{
				if(f) cout<<" ";
				cout<<j-1;
				f=1;
			}
			return ;
		}
	}
} 
 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
*/ 
