#include <bits/stdc++.h>
using namespace std;
int n,m,k;
string s;
int cnt[200010];
int dp[200010][6][2];
//dp[i][j][0]前i个字符，有k段1大于等于x，当前不在第k段末尾的最小代价 
//dp[i][j][1]前i个字符，有k段1大于等于x，当前在第k段末尾的最小代价
bool ck(int x)
{
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j][0]=dp[i][j][1]=1e9;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{	
			if(s[i]=='1')
			{
				dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]);
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
			}
			else
			{
				dp[i][j][0]=min({dp[i][j][0],dp[i-1][j][1],dp[i-1][j][0]});
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]+1);
			}
			if(j>=1&&i>=x)
			{
				dp[i][j][1]=min(dp[i][j][1],dp[i-x][j-1][0]+cnt[i]-cnt[i-x]);
			}
		}
	}
	return min(dp[n][k][0],dp[n][k][1])<=m;
}

void solve()
{
	cin>>n>>m>>k;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+(s[i]=='0');
	int l=0,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)) l=mid+1;
		else r=mid-1;
	}
	l--;
	if(l) cout<<l<<"\n";
	else cout<<"-1\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
