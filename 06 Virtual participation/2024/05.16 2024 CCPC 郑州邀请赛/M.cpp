#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,m,a[300010],b[300010];
int ck(int x)
{
	int mx=a[1]-x*b[1],mi=a[1]+x*b[1];
	for(int i=2;i<=n;i++)
	{
		mi=min(mi,a[i]+x*b[i]);
		mx=max(mx,a[i]-x*b[i]);
		if(mx>mi) return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	l=0,r=1e9;
	while(l<=r)
	{
	//	cout<<l<<" "<<r<<"\n";
		m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;		
	}
	cout<<l<<'\n';
}
signed main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
