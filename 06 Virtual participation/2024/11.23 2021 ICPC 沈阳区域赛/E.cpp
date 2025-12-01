#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(i+4<s.size()&&s.substr(i,5)=="edgnb") ans++;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
