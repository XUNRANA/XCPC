#include <bits/stdc++.h>
using namespace std;
int n,ans,p1,p2;
vector<int>g[200010];
int d[200010],c[200010],f[200010];
void dfs(int u,int fa)
{
	d[u]=d[fa]+1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
void solve()
{
    cin>>n;
	for(int i=0;i<=n;i++) g[i].clear(),f[i]=d[i]=c[i]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>f[i];
		g[f[i]].push_back(i);
		c[f[i]]++;
	}
	dfs(1,0);
	priority_queue<pair<int,int> >q;
	for(int i=1;i<=n;i++) if(c[i]==0) q.push({d[i],i});
	ans=0;
	while((int)q.size()>=2)
	{
		p1=q.top().second;q.pop();
		p2=q.top().second;q.pop();
		ans++;
		if(--c[f[p1]]==0) q.push({d[f[p1]],f[p1]});
		if(--c[f[p2]]==0) q.push({d[f[p2]],f[p2]});
	}
	cout<<ans<<"\n";
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}







/*
#include <bits/stdc++.h>
using namespace std;
vector<int>g[200010];
int s[200010];
int n,t1;
void dfs(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		s[u]+=s[v];
	}
}
int dfs1(int u,int fa)
{
	int mx=0,index=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		if(s[v]>mx)
		{
			mx=s[v];
			index=v;
		}
	}
	if(s[u]-1>=2*mx) return (s[u]-1)/2;
	else 
	{
		int v=dfs1(index,u);
		return v+min((s[u]-1-2*v)/2,s[u]-1-mx);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear(),s[i]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>t1;
		g[t1].push_back(i);
	}
	dfs(1,0);
	cout<<dfs1(1,0)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
*/
