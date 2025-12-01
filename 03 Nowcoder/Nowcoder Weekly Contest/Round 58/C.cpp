#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x,y;
	cin>>x>>y;
	if(x<0||y<0)
	{
		cout<<"PING\n";
		return ;
	}
	if((x+y)&1) 
	{
		if(abs(x-y)>1) cout<<"PING\n";
		else cout<<"YES\n";
	}
	else 
	{
		if(abs(x-y)>1) cout<<"PING\n";
		else cout<<"NO\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

