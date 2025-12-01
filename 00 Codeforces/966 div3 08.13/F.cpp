#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int>dp(k+1,1e9);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		vector<int>c(k+1,1e9);
		c[0]=0;
		int cnt=0,cost=0;
		while(cnt<k&&(a||b))
		{
			if(a>b) swap(a,b);
			cnt++;
			cost+=a;
			b--;
			c[cnt]=cost;
		}
		for(int j=k;j>=0;j--)
		{
			for(int i=0;i<=j;i++)
			{
				dp[j]=min(dp[j],dp[j-i]+c[i]);
			}
		}
	}
	cout<<(dp[k]==1e9? -1:dp[k])<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
