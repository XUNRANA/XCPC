#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,ans,a[100010],s;
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]-=x;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		ans=max(ans,s);
		if(s<0) s=0;
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
