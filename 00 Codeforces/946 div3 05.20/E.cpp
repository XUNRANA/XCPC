#include <bits/stdc++.h>
using namespace std;
#define int long long
int s,m,x,c[60],h[60]; 
void solve()
{
	s=0;
	cin>>m>>x;
	for(int i=1;i<=m;i++) cin>>c[i]>>h[i],s+=h[i];
	vector<int>dp(s+1,-1e18);
	dp[0]=0;//dpi表示获得幸福值i时可以剩余的最多的金币 
	for(int i=1;i<=m;i++)
	{
		for(int j=s;j>=0;j--)
		{
			if(j>=h[i]&&dp[j-h[i]]>=c[i]) dp[j]=max(dp[j],dp[j-h[i]]-c[i]);
			dp[j]+=x;//每月领取工资 
		}
	}
	for(int i=s;i>=0;i--) 
	if(dp[i]>=0) 
	{
		cout<<i<<'\n';
		return ;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
