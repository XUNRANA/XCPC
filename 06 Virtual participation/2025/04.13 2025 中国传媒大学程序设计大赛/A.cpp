#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s,t;
	getline(cin,s);
	getline(cin,t);
	if(s==t) cout<<"Yes\n";
	else cout<<"No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}  
