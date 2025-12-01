#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	cin>>s;
	cout<<s.substr(0,s.size()/2)<<"\n"<<s.substr(s.size()/2);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

