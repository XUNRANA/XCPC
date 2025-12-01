#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int x)
{
	return x*x*x*x;
}
void solve()
{
	int n,m,t;
	cin>>n>>m;
	vector<int>dp(m+1,1e18),a(m+1);
	dp[0]=0;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++) 
	{
		t=a[i];
		dp[i]=min(dp[i],dp[i-1]+t+1);
		for(int j=max(1ll,i-30);j<i;j++)
		{
			if(dp[j-1]+fx(i-j+1)+a[i]<dp[i]) dp[i]=dp[j-1]+fx(i-j+1)+a[i];
		}
	}
	cout<<dp[m]<<'\n';
}
signed main()
{
	int T=1;
	//cin>>T;
	while(T--) solve();
}
