#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	cout<<(a+b+c+d+e>100? "YES":"NO");
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
