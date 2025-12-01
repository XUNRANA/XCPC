#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,q;
	map<string,string>mp;
	cin>>n;
	while(n--)
	{
		string s,t;
		cin>>s>>t;
		mp[t]=s;
	}
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		cout<<mp[s]<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
