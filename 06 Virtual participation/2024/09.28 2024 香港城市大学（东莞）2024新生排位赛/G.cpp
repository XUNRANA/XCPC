#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,ans[100010],dp[100010];
void init()
{
	dp[0]=dp[1]=1;
	dp[2]=2;
	for(int i=2;i<=100000;i++) dp[i]=(dp[i-2]+dp[i-1])%P;
	ans[0]=1;
	for(int i=1;i<=100000;i++) ans[i]=ans[i-1]*dp[i]%P;
}

void solve()
{
	cin>>n;
	cout<<ans[n]<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
