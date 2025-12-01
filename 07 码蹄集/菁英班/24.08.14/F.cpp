#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[60];
void solve()
{
	cin>>n;
	for(int i=3;i<60;i++) dp[i]=1e18;
	dp[0]=0,dp[1]=1,dp[2]=3;
	cout<<"1\n"<<"3\n";
	for(int i=3;i<=n;i++)
	{
		for(int k=1;k<i;k++)
		{
			if(dp[i]>2*dp[i-k]+(1ll<<k)-1) dp[i]=2*dp[i-k]+(1ll<<k)-1;
		}
		cout<<dp[i]<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

