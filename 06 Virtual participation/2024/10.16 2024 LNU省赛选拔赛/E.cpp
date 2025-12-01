#include <bits/stdc++.h>
using namespace std;
#define P 998244353
#define int long long
int dp[15000001];
void solve()
{
	string s;
	cin>>s;
	dp[0]=1;
	dp[1]=2;
	for(int i=2;i<s.size();i++)
	{
		dp[i]=(dp[i-1]+dp[i-2])%P;
		if(s[i]!=s[i-2]) dp[i]=(dp[i]+dp[i-2])%P;
	}
	cout<<dp[s.size()-1]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
