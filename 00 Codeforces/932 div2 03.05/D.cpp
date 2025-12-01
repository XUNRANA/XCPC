#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,t,c0,c1,ans;
void solve()
{
	ans=c0=c1=0;
	cin>>n>>l;
	ans=(l+2)*(l+1)/2;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		ans-=t/2+1;
		ans-=(l-t+1);
		if(t&1) c1++,ans+=c1;
		else c0++,ans+=c0;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
