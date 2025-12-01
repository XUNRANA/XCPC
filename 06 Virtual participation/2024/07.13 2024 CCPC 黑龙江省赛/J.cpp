#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1010][1010],b[1010][1010],dp[1010][1010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
	dp[1][2]=a[1][2]-a[1][1]-b[1][1]-b[1][2];
	dp[2][1]=a[2][1]-a[1][1]-b[1][1]-b[2][1];
	for(int j=3;j<=m;j++) dp[1][j]=dp[1][j-1]-a[1][j-1]+a[1][j]-b[1][j];
	for(int i=3;i<=n;i++) dp[i][1]=dp[i-1][1]-a[i-1][1]+a[i][1]-b[i][1];
	for(int i=2;i<=n;i++) for(int j=2;j<=m;j++)
	dp[i][j]=max(dp[i-1][j]-a[i-1][j]+a[i][j]-b[i][j],dp[i][j-1]-a[i][j-1]+a[i][j]-b[i][j]);
	int f=0;
	for(int i=1;i<=n;i++) if(dp[i][m]>=0) f=1;
	for(int j=1;j<=m;j++) if(dp[n][j]>=0) f=1;
	if(f) cout<<"YES\n";
	else cout<<"NO\n";
}
