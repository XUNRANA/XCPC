#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mx,ans;
int a[100010];
void solve()
{
	cin>>n;
	mx=0;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	ans=0;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		if(f&&a[i]!=mx)
		{
			ans+=mx-a[i];
			f=0;
		}
		else if(a[i]>=a[i-1]) continue;
		else ans+=a[i-1]-a[i];
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
