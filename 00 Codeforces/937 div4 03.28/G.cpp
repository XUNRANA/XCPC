#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<string>g(n),w(n);
	for(int i=0;i<n;i++) cin>>g[i]>>w[i];
	vector<int>e(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(g[i]==g[j]||w[i]==w[j]) e[i]|=1<<j;
		}
	}
	//e[i]的二进制第j位为1表示i可以和j连接 
	vector<int>dp(1<<n);
	for(int x=0;x<n;x++) dp[1<<x]|=1<<x;//可以直接连接在一起 
	
	
	int ans=0;
	for(int s=1;s<(1<<n);s++)
	{
		if(dp[s]) ans=max(ans,__builtin_popcount(s));//返回二进制数1的个数 
		for(int y=0;y<n;y++)
		{
			if((~s>>y&1)&&(dp[s]&e[y]))//判断连接条件 
			{
				dp[s|1<<y]|=1<<y;
			}
		}
	}
	cout<<n-ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
