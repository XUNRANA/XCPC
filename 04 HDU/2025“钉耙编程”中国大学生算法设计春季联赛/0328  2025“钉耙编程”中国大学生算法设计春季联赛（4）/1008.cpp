#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>a(n+1,vector<int>(k+1,0));
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    vector<vector<int>>dp1(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) cin>>a[i][j];
    
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=max(dp1[i-1][j]+a[i][j],dp[i][j]);
            
            dp1[i][j]=max(dp[i][j],dp1[i][j-1]);
        }
    }
    int ans=0;
    for(int j=1;j<=k;j++) ans=max(ans,dp[n][j]);
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}