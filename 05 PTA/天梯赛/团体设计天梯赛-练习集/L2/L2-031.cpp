#include <bits/stdc++.h>
using namespace std;
int n,k,x;
vector<int>g[100010];
int dp[100010];
int mx;
void dfs(int u,int d)
{
	dp[u]=d;
	mx=max(mx,d);
	for(auto v:g[u]) dfs(v,d+1);
}
void solve()
{
	cin>>n;
	vector<int>d(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x;
			g[i].push_back(x);
			d[x]++;
		}
	}
	for(int i=1;i<=n;i++)
	if(!d[i]) dfs(i,1);
	
	for(int i=1;i<=n;i++) if(dp[i]==mx) cout<<i;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

