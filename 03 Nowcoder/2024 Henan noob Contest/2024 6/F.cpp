#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,ans,a[100010];

void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	p=a[n];
	for(int i=n-1;i>=2;i--)
	{
		if(a[i]>=p) p=a[i],ans++;
	}
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
