#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,mx,ans,s,a[200010];
void solve()
{
	cin>>n>>k;
	s=mx=ans=0;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i],mx=max(mx,a[i]);
	for(int i=1;i<=n;i++)//每堆i个 
	{
		//每堆的个数*（至少有mx堆），（s/i上取整堆）*每堆的个数 
		int res=max(i*mx,(s+i-1)/i*i);
		if(res<=s+k) ans=max(ans,i);
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
