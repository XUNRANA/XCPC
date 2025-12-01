#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
int dp[70][70];
void init()
{
	for(int i=60;i>=0;i--) for(int j=60;j>=0;j--) dp[i][j]=0x3f3f3f3f3f3f3f3f;
	dp[0][0]=0;
	for(int k=1;k<=60;k++)
	{
		for(int i=60;i>=0;i--)
		{
			for(int j=60;j>=0;j--)
			{
				if(i>=k) dp[i][j]=min(dp[i][j],dp[i-k][j]+(1ll<<k));
				if(j>=k) dp[i][j]=min(dp[i][j],dp[i][j-k]+(1ll<<k));
			}
		}
	}
}
void solve()
{
	int x,y;
	cin>>x>>y;
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=60;i>=0;i--) for(int j=60;j>=0;j--) if((x>>i)==(y>>j)) ans=min(ans,dp[i][j]);
	cout<<ans<<"\n";
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

