#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	string s;
	cin>>s;
	int ans=0,s1=0;
	for(auto i:s)
	{
		s1+=i-'0';
		if(s1%9==0) ans++;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
