#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,dp[N],t,ans;
void solve()
{
	dp[1]=0;
	for(int i=2;i<=100000;i++)
	{
		dp[i]=dp[i-1]+1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				dp[i]=min(dp[i],dp[i/j]+dp[j]+1);
			}
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		ans+=dp[t];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

