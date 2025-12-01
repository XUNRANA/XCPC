#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	int res=c*b;
	int now=1,ans=0;
	while(now<c)
	{
		res=min(res,(c+now-1)/now*b+ans);
		ans+=a;
		now*=2;
	}
	ans+=b;
	res=min(ans,res);
	cout<<res<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
