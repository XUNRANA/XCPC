#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(c*d+(100-c)*1>a*b+(100-a)*1) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
