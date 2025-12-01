#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1010
int n,m,q,a[N][N];
int dp[N][N][4];

void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]=-1e18;
	dp[1][1][0]=a[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j-1>=1)
			{
				if(__gcd(a[i][j-1],a[i][j])==1)
				{
					for(int k=1;k<=q;k++)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+a[i][j]);
					}
				}
				else
				{
					for(int k=0;k<=q;k++)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i][j]);
					}
				} 
				
			}
			
			if(i-1>=1)
			{
				if(__gcd(a[i-1][j],a[i][j])==1)
				{
					for(int k=1;k<=q;k++)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][j]);
					}
				}
				else
				{
					for(int k=0;k<=q;k++)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][j]);
					}
				}
			}
			
		}
	}
	int ans=0;
	for(int k=0;k<=q;k++) ans=max(ans,dp[n][m][k]);
	if(ans==0) ans=-1;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
