#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b) cout<<c;
	else if(b==c) cout<<a;
	else cout<<b;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
