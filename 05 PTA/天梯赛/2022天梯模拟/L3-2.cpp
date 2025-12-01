#include <bits/stdc++.h>
using namespace std;


int a[1010];
int b[1010];
int dp[30010];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n*30;i++) dp[i]=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=n*30;j>=b[i];j--) dp[j]=min(dp[j],dp[j-b[i]]+a[i]);
	}
	int ans=0;
    for(int i=1;i<=n*30;i++) if(dp[i]<=m) ans=max(ans,i);
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
