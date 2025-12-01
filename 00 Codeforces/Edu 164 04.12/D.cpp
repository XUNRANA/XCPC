#include <bits/stdc++.h>
using namespace std;
#define P 998244353	
#define int long long
int n,a[5010],dp[5050],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=0;i<=5000;i++) dp[i]=0;
	dp[0]=1;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			if(j<a[i]) ans=(ans+a[i]*dp[j]%P)%P;
			else ans=(ans+(a[i]+j+1)/2*dp[j]%P)%P;
		}
		for(int j=5000;j>=0;j--) dp[a[i]+j]=(dp[a[i]+j]+dp[j])%P;
	}
	cout<<ans<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--) solve();
}
