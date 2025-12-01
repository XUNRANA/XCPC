#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,r,m,mx,n,k,a[123460],b[123460],p[123460];
void solve()
{
	cin>>n>>k; 
	mx=0;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(a[i],mx);
	for(int i=1;i<=n;i++) cin>>p[i];
	l=0,r=mx;
	while(l<=r)
	{
		m=l+r>>1;
		for(int i=1;i<=n;i++) b[i]=a[i]-m,b[i]+=b[i-1];
		
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t1=1;
	cin>>t1;
	while(t1--) solve();
}
