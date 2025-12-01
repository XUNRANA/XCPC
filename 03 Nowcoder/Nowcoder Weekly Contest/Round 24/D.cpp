#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,a[100010];
int ck(int mid)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=mid) continue;
		else cnt+=(a[i]-mid+x-1)/x;
		if(cnt>k) return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=-1e18,r=1e18;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
    cout<<l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

