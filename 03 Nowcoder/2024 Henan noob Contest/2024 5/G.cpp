#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 1000000007
int n,dp[1000010];
void solve()
{
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=1) dp[i]=(dp[i]+dp[i-1])%P;
		if(i>=2) dp[i]=(dp[i]+dp[i-2])%P;
		if(i>=3) dp[i]=(dp[i]+dp[i-3])%P;
	}
	cout<<dp[n]<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
