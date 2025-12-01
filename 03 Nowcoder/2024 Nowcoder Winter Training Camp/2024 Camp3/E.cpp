#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans=-1e18;
int a[1010];
int dp[1010][1010];
void solve()
{
	cin>>n>>k;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      ans=max(ans,a[i]);
    }
    if(ans<0) 
	{
		cout<<ans;
		return ; 
	}
    for(int i=1;i<=n;i++)
    for(int j=min(n,i+k);j>=max(1ll,i-k);j--)
    for(int l=abs(j-i);l<=k;l++)
    {
    	dp[j][l]=max(dp[j][l],dp[j-1][l-abs(j-i)]+a[i]);
        ans=max(dp[j][l],ans);
    }
    cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
