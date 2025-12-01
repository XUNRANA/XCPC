#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],b[200010];
int dp[200010][2];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    dp[1][0]=a[1];
    dp[1][1]=-1e18+b[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i];
        dp[i][1]=dp[i-1][1]+b[i];
        if(dp[i-1][1]>=k) dp[i][0]=max(dp[i-1][1]-k+a[i],dp[i][0]);
        if(dp[i-1][0]>=k) dp[i][1]=max(dp[i-1][0]-k+b[i],dp[i][1]);
    }
    cout<<max(dp[n][0],dp[n][1])<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
