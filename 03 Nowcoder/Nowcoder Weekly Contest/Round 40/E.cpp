#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y;
void solve()
{
	cin>>n>>x>>y;
	cout<<max({n*n/4*y,n*n/3*x,(n*n/3-1)*x+y})<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
