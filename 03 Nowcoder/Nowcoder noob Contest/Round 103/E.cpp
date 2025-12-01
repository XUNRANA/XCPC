#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[100010],b[100010],c[100010];
int g(int x)
{
	int ans=0;
	for(int i=c[x];i<=n;i++) ans+=(a[i]%x==0);
	return ans;
//	cout<<x<<" "<<ans<<"\n";
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) g(i);
	while(q--)
	{
		int x,f=0;
		cin>>x;
		for(int i=x+1;i<=n;i++) 
		if(__gcd(b[i],b[x])!=1) 
		{
			x=__gcd(b[i],b[x]);
			f=1;
			break;
		}
		if(!f) x=b[x];
		cout<<g(x)<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
