#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int x;
	cin>>x;
	if(x%10==0) cout<<"0\n";
	else cout<<10-x%10<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
