#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	if(x*x+y*y+z*z==3*x*y*z) cout<<"Yes\n";
	else cout<<"No\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
