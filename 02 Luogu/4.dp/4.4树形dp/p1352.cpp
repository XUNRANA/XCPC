#include <bits/stdc++.h>
using namespace std;
#define N 6010
int r[N],v[N],l,k,n,root;
vector<int>g[N];
int dp[N][2];
void dfs(int u)
{
	if(r[u]>0) dp[u][1]=r[u];
	for(auto v:g[u])
	{
		dfs(v);
		dp[u][1]+=dp[v][0];
		dp[u][0]+=dp[v][1];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int i=1;i<n;i++)
	{
		cin>>l>>k;
		g[k].push_back(l);
		v[l]=1;
	}
	for(int i=1;i<=n;i++) 
	if(!v[i])
	{
		root=i;
		break;
	}
	dfs(root);
	cout<<max(dp[root][1],dp[root][0]);
}
