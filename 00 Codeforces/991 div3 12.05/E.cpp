#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1010][1010];
void solve()
{
	string a,b,c;
	cin>>a>>b>>c;
	int na=a.size();
	int nb=b.size();
	a=" "+a;
	b=" "+b;
	c=" "+c;
	for(int i=0;i<=na;i++) for(int j=0;j<=nb;j++) dp[i][j]=1e9;
	dp[0][0]=0;
	for(int i=0;i<=na;i++)
	{
		for(int j=0;j<=nb;j++)
		{
			if(i>0) dp[i][j]=min(dp[i-1][j]+(a[i]!=c[i+j]),dp[i][j]);
			if(j>0) dp[i][j]=min(dp[i][j-1]+(b[j]!=c[i+j]),dp[i][j]);
		}
	}
	
	cout<<dp[na][nb]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
