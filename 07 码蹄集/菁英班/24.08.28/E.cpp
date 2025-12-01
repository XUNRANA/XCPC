#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 500010
#define P 1000000007
int f[N][30][2],a[N],st[N],top,k;
vector<int>g[N];
void dfs(int u,int fa)//树上差分 
{
	st[++top]=u;
	for(int i=0;i<30;i++) f[u][i][a[u]>>i&1]++;
	if(top>k+1)//至少为k+2 
		for(int i=0;i<30;i++) 
			f[st[top-k-1]][i][a[u]>>i&1]--;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
	top--;//回溯 
}
void dfs1(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs1(v,u); 
		for(int i=0;i<30;i++) //自底向上求和 
		{
			f[u][i][0]+=f[v][i][0];
			f[u][i][1]+=f[v][i][1];
		}
	}
}
void solve()
{
	int n,q;
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	dfs(1,0);
	dfs1(1,0);
	while(q--)
	{
		int x;
		cin>>x;
		int ans=0;
		for(int i=0;i<30;i++) ans=(ans+f[x][i][0]*f[x][i][1]%P*(1ll<<i)%P)%P;
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

