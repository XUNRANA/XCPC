#include <bits/stdc++.h>
using namespace std;
const int P=2333;
int n,m,a[3010][3010],dp[3010][3010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	
	dp[m][1]=1;
	for(int i=m;i>=1;i--) for(int j=1;j<=n;j++) 
	if(a[i][j]) continue;
	else 
	{
		if(a[i][j-1]==0) dp[i][j]=(dp[i][j]+dp[i][j-1])%P;
		if(a[i+1][j]==0) dp[i][j]=(dp[i][j]+dp[i+1][j])%P;
	}
	cout<<dp[1][n]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

