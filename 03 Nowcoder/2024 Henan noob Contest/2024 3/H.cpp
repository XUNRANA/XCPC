#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m,h;
	cin>>n>>m>>h;
	vector<vector<int>>a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(3010,0))); 
	dp[1][1][0]=h;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=n+m-2;k++)
			{
				dp[i][j][k]=max({dp[i][j-1][k]-a[i][j],dp[i-1][j][k]-a[i][j],dp[i][j][k]});
				if(k>=1) dp[i][j][k]=max({dp[i][j-1][k-1],dp[i-1][j][k-1],dp[i][j][k]});
			}
		}
	}
	
	for(int k=0;k<=n+m-2;k++) 
	if(dp[n][m][k]>0) 
	{
		cout<<k<<"\n";
		return ;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
