#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,p,k,ans,dp[2][2010];
void solve()
{
	cin>>n>>p;
	for(int i=0;i<=2000;i++) dp[0][i]=dp[1][i]=1e18;
	for(int i=1;i<=n;i++,k^=1)
	{
		cin>>t;
		t%=p;
		dp[k^1][t]=1;
		for(int j=0;j<p;j++) dp[k^1][j]=min(dp[k][j],dp[k^1][j]);
		for(int j=0;j<p;j++) dp[k^1][(j+t)%p]=min(dp[k^1][(j+t)%p],dp[k][j]+1);
	}
    ans=dp[k][0];
    for(int i=1;i<p;i++) ans=min(ans,dp[k][i]+dp[k][p-i]);
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
