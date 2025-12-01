#include <bits/stdc++.h>
using namespace std;
#define N 310
int l,n,m;
int a[N];
int b[N][N];
int dp[N][N][N];
void solve()
{
	cin>>l>>n>>m;
	for(int i=1;i<=l;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j]; 
	
	for(int i=0;i<=l+1;i++) for(int j=0;j<=n+1;j++) for(int k=0;k<=m+1;k++) dp[i][j][k]=0;
	
	for(int i=l;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			for(int k=m;k>=1;k--)
			{
				if(b[j][k]==a[i]&&!dp[i+1][j+1][k+1]) dp[i][j][k]=1;
				dp[i][j][k]+=dp[i][j+1][k]+dp[i][j][k+1]-dp[i][j+1][k+1];
			}
		}
	}
	
	if(dp[1][1][1]) cout<<"T\n";
	else cout<<"N\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T; 
	while(T--) solve();
}
