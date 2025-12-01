#include <bits/stdc++.h>
using namespace std;
struct info
{
	int v,w,id;
	vector<bool>vv;
	bool operator<(const info &a)const
	{
		return w>a.w;
	}
};

struct ifo
{
	int v,w,id;
};

int n,x,a[110];
priority_queue<info>q;
vector<ifo>g[210];
int vt[210],dis[210];
int pre[210],preid[210];
void solve()
{
	cin>>n>>x;
	x+=100;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=0;i<=200;i++)
	{
		if(i<100)
		{
			for(int j=1;j<=n;j++)
			g[i].push_back({i+a[j],a[j],j});
		}
		else
		{
			for(int j=1;j<=n;j++)
			g[i].push_back({i-a[j],a[j],j});
		}
	}
    
	for(int i=0;i<=200;i++) vt[i]=0,dis[i]=1e9;
	vector<bool>vv(n+1,0);
	q.push({x,0,0,vv});
	dis[x]=0;
	while(!q.empty())
	{
		int u=q.top().v;
		auto vs=q.top().vv;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.v;
			int w=v1.w;
			int id=v1.id;
			if(!vs[id]&&dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pre[v]=u;
				preid[v]=id;
				auto vss=vs;
				vss[id]=1;
				q.push({v,dis[v],id,vss});
			}
		}
	}
	
	if(dis[100]==1e9)
	{
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		cout<<sum<<"\n"; 
		for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<"\n";
	}
	else
	{
		cout<<dis[100]<<"\n";
		int nxt=100;
		vector<int>ans;
		vector<bool>vis(n+1,0);
		if(pre[nxt])
		{
			while(1)
			{
				ans.push_back(preid[nxt]);
				vis[preid[nxt]]=1;
				if(pre[nxt]==x) break;
				nxt=pre[nxt];
			}
		}
		reverse(ans.begin(),ans.end());
		for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(i);		
		for(auto i:ans) cout<<i<<" ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
