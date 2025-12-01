#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<b*d+a*min(c,d)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
