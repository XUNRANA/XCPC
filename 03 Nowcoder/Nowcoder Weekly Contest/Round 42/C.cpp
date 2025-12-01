#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,mi,mx,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	mi=1e18;
	mx=-1e18;
	if(n&1)
	{
		mi=min(mi,a[n]);
		mx=max(mi,a[n]);
		n--;
	}
	for(int i=1;i<=n/2;i++)
	{
		mi=min(mi,a[i]*a[n-i+1]);
		mx=max(mx,a[i]*a[n-i+1]);
	}
	cout<<mx-mi<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
