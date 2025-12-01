#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,ans=0;
	string s;
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		if(s[u]==s[v]) ans++;
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
