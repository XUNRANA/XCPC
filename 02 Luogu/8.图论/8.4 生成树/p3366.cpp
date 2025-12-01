#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
int n,m,x,y,z,vt[N],ans,fa[N];
vector<pair<int,int>>g[N];
vector<pair<int,pair<int,int>>>e;
void prim()
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,1});
	while(!q.empty())
	{
		int w=q.top().first;
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		ans+=w;
		for(auto v:g[u]) q.push(v);
	}
	for(int i=1;i<=n;i++) 
	if(!vt[i])
	{
		cout<<"orz\n";
		return ;
	}
	cout<<ans<<"\n";
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void kruskal()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e.begin(),e.end());
	for(auto i:e)
	{
		int w=i.first;
		int u=i.second.first;
		int v=i.second.second;
		if(find(u)==find(v)) continue;
		ans+=w;
		fa[find(u)]=find(v);
	}
	set<int>st;
	for(int i=1;i<=n;i++) st.insert(find(i));
	if(st.size()==1) cout<<ans<<"\n";
	else cout<<"orz\n";
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		e.push_back({z,{x,y}});
		g[x].push_back({z,y});
		g[y].push_back({z,x});
	}
	kruskal();
	//prim();
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
