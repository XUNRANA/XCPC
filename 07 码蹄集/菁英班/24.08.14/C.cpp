#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[110][51][2];
void solve()
{
	string s;
	cin>>s>>n;
	s=" "+s;
	for(int i=0;i<s.size();i++) for(int j=0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=-1e18;
	dp[0][0][0]=dp[0][0][1]=0;
	for(int i=1;i<s.size();i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=j;k++)
			{
				if(s[i]=='F')
				{
					if(k%2)
					{
						dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][0]);
						dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][0]);
					}
					else
					{
						dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][0]+1);
						dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][1]-1);
					}
				}
				else 
				{					
					if(k%2)
					{
						dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][0]+1);
						dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][1]-1);
					}
					else
					{
						dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][1]);
						dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][0]);
					}
				}
			}
		}
	}
	cout<<max(dp[s.size()-1][n][0],dp[s.size()-1][n][1]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

