#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x,y,ans;
	cin>>x>>y;
	if(x==y) 
	{
		cout<<"-1\n";
		return ;
	}
	if(x>y) swap(x,y);
	for(int i=60;i>=0;i--) if(y>>i&1) 
	{
		ans=(1ll<<(i+1))-y;
		break;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
