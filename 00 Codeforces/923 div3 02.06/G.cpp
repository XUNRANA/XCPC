#include <bits/stdc++.h>
using namespace std;
int n,dp[110][110];//dp[i,j]考虑使用前i个位置使[1,j]涂满 
void solve()
{
	cin>>n;
	for(int i=0;i<110;i++) for(int j=0;j<110;j++) dp[i][j]=1e9; 
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<=n;j++)
		{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		}	
	}
	for(int i=0;i<=n;i++,cout<<"\n")
	for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
	cout<<"\n\n";
	/*
	for(int j=0;j<n;j++)
	{
		int l=max(1,i+1-a[i+1]+1),r=i+1;
		if(j>=l-1)  dp[i+1][max(r,j)]=min(dp[i+1])
	} */
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
