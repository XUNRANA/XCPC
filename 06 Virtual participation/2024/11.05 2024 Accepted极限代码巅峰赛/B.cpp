#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[1000010];
int dp[1000010][2];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],dp[i][0]=dp[i][1]=0;
	
	if(k==1)
	{
		int s=0;
		for(int i=1;i<=n;i++) s+=a[i];
		cout<<s<<"\n";
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			if(i>=k) dp[i][1]=max(dp[i-1][1],dp[i-k+1][0])+a[i];
		}
		cout<<max(dp[n][1],dp[n][0])<<"\n";
	}                                                 
	
	
	
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
