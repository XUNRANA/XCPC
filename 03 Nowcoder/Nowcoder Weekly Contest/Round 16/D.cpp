#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<pair<pair<int,int>,int>>g[N];
int n,m,vt[N],u[N],v[N],w[N],p[N],fa[N],ans;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i]>>p[i];
	vector<int>ans;
	for(int i=1;i<=m;i++) 
	if(p[i]) 
	{
		ans.push_back(i);
		fa[find(u[i])]=find(v[i]);
	}
	for(int i=1;i<=m;i++)
	if(!p[i])
	{
		if(find(u[i])!=find(v[i]))	
		{
			g[find(u[i])].push_back({{w[i],find(v[i])},i});
			g[find(v[i])].push_back({{w[i],find(u[i])},i});
		}
	}
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>q;
	q.push({{0,find(1)},0});
	while(!q.empty())
	{
		int u=q.top().first.second;
		int w=q.top().first.first;
		int idx=q.top().second;
		q.pop();
		if(vt[u]) continue;
		if(idx) ans.push_back(idx);
		vt[u]=1;
		for(auto v:g[u])
		{
			if(vt[v.first.second]) continue;
			q.push(v);
		}
	}
    for(int i=1;i<=n;i++) 
    if(!vt[find(i)])
    {
        cout<<"-1\n";
        return ;
    }
    sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
