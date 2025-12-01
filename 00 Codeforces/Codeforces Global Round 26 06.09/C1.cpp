#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,a[200010],sa[200010],pa[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pa[i]=pa[i-1]+a[i];
	ans=pa[n];
	sa[n+1]=0;
	for(int i=n;i>=1;i--) sa[i]=sa[i+1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,-pa[i]+sa[i]-a[i]);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
