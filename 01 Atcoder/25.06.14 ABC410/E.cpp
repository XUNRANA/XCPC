#include <bits/stdc++.h>
using namespace std;
int n,h,m;
int dp[3010][6010];
void solve()
{
	cin>>n>>h>>m;
	for(int i=0;i<=3000;i++)
	for(int j=0;j<=6000;j++) dp[i][j]=-1;
	dp[0][m]=h;
	for(int i=1;i<=n;i++) 
	{
		int a,b;
		cin>>a>>b;
		int f=0;
		for(int j=0;j<=m;j++)
		{	
			dp[i][j]=max(dp[i-1][j+b],dp[i-1][j]-a);
			if(dp[i][j]>=0) f=1;
		}
		if(!f)
		{
			cout<<i-1<<"\n";
			return ;
		}
	}
	cout<<n<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
