#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[410];
int dp[410][410];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=0;
    
    for(int r=3;r<=n;r++) 
    {
        for(int l=r-2;l>=1;l--)
        {
            for(int i=l+1;i<=r-1;i++)
            {
                dp[l][r]=max(dp[l][r],dp[l+1][i-1]+dp[i+1][r-1]+a[l]*a[i]*a[r]);
            }
            for(int i=l;i<=r;i++) dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
        }
    }
    cout<<dp[1][n]<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

