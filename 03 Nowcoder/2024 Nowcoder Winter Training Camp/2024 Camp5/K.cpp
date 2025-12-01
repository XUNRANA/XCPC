#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,a,b,ans,dp[1010];
void solve()
{
	cin>>n>>p;
    for(int i=1;i<n;i++) dp[i]=p*i; 
	for(int i=1;i<=n;i++)
	{
        cin>>a>>b;
        if(b>=n) b=n-1; 
        for(int j=0;j<n;j++) dp[j]=min(dp[j],dp[max(j-b,0ll)]+a);
	}
    cout<<dp[n-1]+p<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
