#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1<<18];//f[s]:出现数字的集合为s的时,所能得到的最大长度 
int dp[1<<18];//dp[s]:出现数字的集合为s的子集时,所能得到的最大长度
int n,a[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int>b;
		for(int j=i;j<=n;j++)
		{
			int fx=0;
			for(auto k:b) 
			{
				if(k==a[j]) 
				{
					fx=1;
					break;
				}
			}
			if(fx) break;
			b.push_back(a[j]);
		}
		
		int sta=0;
		int cnt=1;
		for(auto k:b) 
		{
			sta|=1<<(k-1);
			f[sta]=max(f[sta],cnt);
			cnt++; 
		}
	}
	for(int i=0;i<(1<<18);i++)
	{
		dp[i]=max(f[i],dp[i]);
		for(int j=0;j<18;j++) if(i>>j&1) dp[i]=max(dp[i],dp[i^(1<<j)]); 
	}
	int ans=0;
	int m=(1<<18)-1;
	for(int i=0;i<(1<<18);i++) ans=max(ans,dp[i]+dp[m^i]);
	cout<<ans<<"\n";
}
/*
7
2 1 1 3 1 1 4
1
1
*/


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
