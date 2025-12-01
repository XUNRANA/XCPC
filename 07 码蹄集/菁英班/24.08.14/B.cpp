#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[40][160];
void solve()
{
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=4*n;j++)
		{
			if(j>=4) dp[i][j]=(dp[i][j]+dp[i-1][j-4]);
			if(j>=3) dp[i][j]=(dp[i][j]+dp[i-1][j-3]);
			if(j>=2) dp[i][j]=(dp[i][j]+dp[i-1][j-2]);
			if(j>=1) dp[i][j]=(dp[i][j]+dp[i-1][j-1]); 
		}
	}
	int ans1=0,ans2=0,s1=(1ll<<(2*n)),s2=s1;
	for(int i=n;i<2*n;i++) ans1+=dp[n][i];
	for(int i=3*n+1;i<=4*n;i++) ans2+=dp[n][i];
	int t1=__gcd(ans1,s1);
	s1/=t1;
	ans1/=t1;
	int t2=__gcd(ans2,s2);
	s2/=t2;
	ans2/=t2;
	cout<<ans1<<"/"<<s1<<"\n";
	cout<<ans2<<"/"<<s2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

