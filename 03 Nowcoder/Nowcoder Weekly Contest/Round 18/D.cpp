#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1010
int n,x,ans,a[N],b[N];
int dp[N][N][2];
void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    
    for(int i=0;i<=n;i++) for(int j=0;j<=x;j++) dp[i][j][0]=dp[i][j][1]=-1e18;

    if(a[1]<=x) dp[1][a[1]][1]=b[1];
    dp[1][0][0]=0;//前1项，花了0块钱，0表示不购买/半价购买
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            //第i项不购买，前一项任意。
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
            
            if(j>=a[i]/2)//第i项半价购买，前一项必须全价
            dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-a[i]/2][1]+b[i]);
            
            if(j>=a[i])//第i项购买，前一项不购买/半价、全价都行
            dp[i][j][1]=max(dp[i-1][j-a[i]][1],dp[i-1][j-a[i]][0])+b[i];
        }
    }

    for(int i=0;i<=x;i++) ans=max({ans,dp[n][i][0],dp[n][i][1]});
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
