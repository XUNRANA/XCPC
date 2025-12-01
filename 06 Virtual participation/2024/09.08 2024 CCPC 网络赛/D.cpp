#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
int dp[110][110][110];
void solve()
{
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	s=" "+s;
	t=" "+t;
	//dp[i][j][k]表示第i层，子序列为(T)j~k的个数 
	for(int i=1;i<=n;i++)//遍历每一层 
	{
		for(int j=1;j<=m;j++) dp[i][j][j]=dp[i-1][j][j]*2%P;//长度为一的区间加倍
		for(int j=1;j<=m;j++)
		{
			for(int k=j+1;k<=m;k++)//枚举长度大于1的区间
			{
				dp[i][j][k]=dp[i-1][j][k]*2%P;//先加倍 
				for(int p=j;p<k;p++)//枚举前后组合的所有情况 
				{
					dp[i][j][k]+=dp[i-1][j][p]*dp[i-1][p+1][k]%P;
					dp[i][j][k]%=P;
				}
			}
		}
		for(int j=1;j<=m;j++)//枚举tj可能等于si的所有情况 
		{
			if(s[i]==t[j])
			{
				dp[i][j][j]++;//[j,j]区间自增 
				for(int k=1;k<j;k++)//j作为右端点带来的贡献，枚举左端点 
				{
					dp[i][k][j]+=dp[i-1][k][j-1];
					dp[i][k][j]%=P;
				}
				for(int k=j+1;k<=m;k++)//j作为左端点带来的贡献，枚举右端点 
				{
					dp[i][j][k]+=dp[i-1][j+1][k];
					dp[i][j][k]%=P;
				}
				for(int k=1;k<j;k++)//枚举区间左端点 
				{
					for(int p=j+1;p<=m;p++)//枚举区间右端点 
					{//j作为中间点带来的贡献 
						dp[i][k][p]+=dp[i-1][k][j-1]*dp[i-1][j+1][p]%P;
						dp[i][k][p]%=P;
					}
				}
			}
		}
	}
	//第n层，子序列为t1~tm的所有个数 
	cout<<dp[n][1][m]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
