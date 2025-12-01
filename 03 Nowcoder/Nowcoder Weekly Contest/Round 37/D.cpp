#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int n;
    string s;
	cin>>n>>s;
    if(s[0]>s[s.size()-1]) cout<<s[0];
    else cout<<s[s.size()-1];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
