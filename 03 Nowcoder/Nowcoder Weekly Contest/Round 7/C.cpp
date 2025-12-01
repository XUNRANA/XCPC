#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,d,l,r;
	cin>>a>>b>>l>>r;
	d=b-a;
	if(d/l*(r-l)<d%l) cout<<"-1\n";
	else cout<<(d+r-1)/r<<" "<<d/l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
