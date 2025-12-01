#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,a[200010],s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=a[1];
	s=0;
	if(a[1]>0) s=a[1];
	for(int i=2;i<=n;i++)
	{
		ans=max(ans,a[i]);
		if((a[i-1]&1)!=(a[i]&1)) 
		{
			s+=a[i];
			ans=max(s,ans);
			if(s<0) s=0;
		}
		else 
		{
			s=0;
			if(a[i]>0) s=a[i];
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
