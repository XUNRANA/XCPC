#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,mn,a[300010],dp[300010][15];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=1e18;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=dp[i-1][j]+a[i];
			mn=a[i];
			for(int k1=1;k1<=j&&i-k1>=1;k1++)
			{
				mn=min(mn,a[i-k1]);
				dp[i][j]=min(dp[i][j],dp[i-(k1+1)][j-k1]+mn*(k1+1));
			}
		} 
	}
	cout<<dp[n][k]<<"\n";
}



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve(); 
}
