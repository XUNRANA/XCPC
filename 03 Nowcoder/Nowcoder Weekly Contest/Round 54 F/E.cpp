#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=i+a[i]-1&&j<=n;j++)
        {
            if(j-a[i]<0) continue;
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    
    if(dp[n]==1e9) dp[n]=-1;
    cout<<dp[n]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
