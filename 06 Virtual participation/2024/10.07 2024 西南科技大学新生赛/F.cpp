#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
string t;
string ans;
int n,m;
void solve()
{
	cin>>n>>m;
	cin>>s>>t;
	ans="";
	ans+=s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=s[i-1]) ans+=s[i];
	}
//	cout<<ans<<" "<<t<<"\n";
	if(ans==t) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
