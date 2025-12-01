#include <bits/stdc++.h>
using namespace std;
int c[13];
int dp[1<<13];
int n,w,x;
void solve()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		c[x-1]++;
	}
	
	for(int i=0;i<(1<<13);i++)//计算状态i的代价 
	{
		int s=0;
		for(int j=0;j<13;j++) if(i>>j&1) s+=c[j];
		if(s<=w) 
		{
			if(s==0) dp[i]=0;//0天可看完 
			else dp[i]=1;//一天可完成
		}
		else dp[i]=1e9;//该状态不能一天完成 
	}

	for(int i=0;i<(1<<13);i++)//计算状态i的最小代价 
	{
		for(int j=0;j<(1<<13);j++)//通过子集转移 
		{
			if(i&j==j)//j是i的子集 
			{
				dp[i]=min(dp[i],dp[i^j]+dp[j]);
			}
		}
	}
	cout<<dp[(1<<13)-1]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
