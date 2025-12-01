#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
vector<int>g[100010];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
int ans,n,u,v;
void dfs(int u,int fa,int cur,int cnt)
{
	if(g[u].size()==1&&u!=1)
	{
		ans=(ans+cur*cnt%P)%P;
		return ;
	}
	int res;
	if(u==1) res=cur*inv(g[u].size())%P;
	else res=cur*inv(g[u].size()-1)%P;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,res,cnt+1);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	if(n==1)
	{
		cout<<1<<"\n";
		return ;
	}
	ans=0;
	dfs(1,0,1,1);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
