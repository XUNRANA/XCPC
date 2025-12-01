#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int n,m,p,ans,a[80][80],dp[80][80][80];
void solve()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	memset(dp,-INF,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==1)
			{
				for(int k=0;k<=m/2;k++)
				{
					for(int l=0;l<p;l++)
					dp[i][0][l]=max(dp[i][0][l],dp[i-1][k][l]);
				}
			}
			
			for(int k=m/2;k>=0;k--)
			{			
				for(int l=0;l<p;l++)
				{
					dp[i][k+1][(l+a[i][j])%p]=max(dp[i][k+1][(l+a[i][j])%p],dp[i][k][l]+a[i][j]);
				}
			}
		}
	}
	for(int j=0;j<=m/2;j++) ans=max(ans,dp[n][j][0]);
	cout<<ans<<"\n";	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

