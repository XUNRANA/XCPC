#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
int w[N],t[N],dp[N][2],n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i]>>t[i];//ÖÊÁ¿ºÍÊ±¼ä 
	for(int i=0;i<=m;i++) dp[i][0]=dp[i][1]=1e18;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			dp[j][0]=min(dp[j][0],dp[max(0ll,j-w[i])][0]+t[i]);//0->0
			dp[j][1]=min({dp[j][1],dp[max(0ll,j-w[i]*2)][0]+t[i]/2,dp[max(0ll,j-w[i])][1]+t[i]});//0->1  1->1
		}
	}
	cout<<dp[m][1];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
//	cin>>T;
	while(T--) solve();
}