#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v,w;
void solve()
{
	cin>>n>>m;
	vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(16,-1e18)));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>v>>w;
		w%=16;
		for(int j=0;j<=m;j++) for(int k=0;k<16;k++) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
		for(int j=m;j>=v;j--)
		{
			for(int k=0;k<16;k++)
			{
            	dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-v][(k+w)%16]+1);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++) ans=max(dp[n][i][0],ans);
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
