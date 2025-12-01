#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,a,p,c,u,l;
int dp[310];
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>p>>c>>u>>l;
		for(int j=x;j>=1;j--)
		{
			if(j>=p) 
			{
				dp[j]=max(dp[j],dp[j-p]+a);
				for(int k=1;k<=l&&j-p>=k*c;k++)
				{
					dp[j]=max(dp[j],dp[j-p-k*c]+a+k*u);
				}
			}
		}
	}
	cout<<dp[x]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
