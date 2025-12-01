#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int fa[N],vt[N],n,m,id;
vector<int>e[N],ans;
struct node
{
	int u,v,w;
}a[N];
bool cmp(node a1,node a2)
{
	return a1.w>a2.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int u,int tag)
{
	vt[u]=1;
	ans.push_back(u);
	if(u==tag)
	{
		cout<<ans.size()<<"\n";
		for(auto i:ans) cout<<i<<" ";
		cout<<"\n";
		return ;
	}
	for(auto v:e[u]) if(!vt[v]) dfs(v,tag);
	ans.pop_back();
}


void solve()
{
	ans.clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i,e[i].clear(),vt[i]=0;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v)) fa[find(a[i].u)]=find(a[i].v);
		else id=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(i==id) continue;
		e[a[i].u].push_back(a[i].v);
		e[a[i].v].push_back(a[i].u);
	}
	cout<<a[id].w<<" ";
	dfs(a[id].u,a[id].v);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}
