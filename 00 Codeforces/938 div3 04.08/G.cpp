#include <bits/stdc++.h>
using namespace std;
int __gcd(int x,int y)
{
	return y==0? x:__gcd(y,x%y);
}
int n,m;
int a[110][110];
void solve()
{
	cin>>n>>m;
	vector<int>dp[n+1][m+1];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	dp[1][1].push_back(a[1][1]);
	for(int i=2;i<=m;i++) a[1][i]=(__gcd(a[1][i],a[1][i-1])),dp[1][i].push_back(a[1][i]);
	
	for(int i=2;i<=n;i++) a[i][1]=(__gcd(a[i][1],a[i-1][1])),dp[i][1].push_back(a[i][1]);
	
	for(int i=2;i<=n;i++) for(int j=2;j<=m;j++)
	{
		for(auto x:dp[i][j-1])
		dp[i][j].push_back(__gcd(a[i][j],x));
		
		for(auto x:dp[i-1][j])
		dp[i][j].push_back(__gcd(a[i][j],x));
		
		sort(dp[i][j].begin(),dp[i][j].end());
		auto it=unique(dp[i][j].begin(),dp[i][j].end());
		dp[i][j].erase(it,dp[i][j].end());	
	}
	cout<<dp[n][m][dp[n][m].size()-1]<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
