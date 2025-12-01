#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	if(x+y>z) cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

