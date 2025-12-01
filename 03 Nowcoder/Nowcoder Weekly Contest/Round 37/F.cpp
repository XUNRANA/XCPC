#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][128],n,t;
void solve()
{
	cin>>n;
	for(int i=0;i<128;i++) dp[0][i]=dp[1][i]=1e9;
	int j=1;
	for(int k=1;k<=n;k++)
	{
		cin>>t;
        for(int i=0;i<128;i++) dp[j^1][i]=dp[j][i];
		dp[j^1][t]=1;
		for(int i=0;i<128;i++)
		if(dp[j][i]!=1e9) dp[j^1][i&t]=min(dp[j^1][i&t],dp[j][i]+1);
		j^=1;
	}
	if(dp[j][0]==1e9) cout<<"-1\n";
	else cout<<n-dp[j][0]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

