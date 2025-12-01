#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	long long a;
	cin>>a;
	long long ans=0;
	for(long long i=1;i<=1e9;i*=10) ans+=a/i;
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
