#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,p,dp[5010][5010],a[5010],t[5010];
void solve()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dp[1][i]=a[i];
	
	for(int i=2;i<=n;i++)
	{
		int s=0;
		for(int j=1;j<i;j++) s=(s+dp[i-1][j])%p;
		for(int j=i;j<=n;j++)
		{
			dp[i][j]=(dp[i][j]+s*a[j]%p)%p;
			s=(s+dp[i-1][j])%p;
		}
	}
	cout<<1<<" ";
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++) ans=(ans+dp[i][j])%p;
		cout<<ans<<" ";
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
