#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	if(s.size()<3)
	{
		cout<<"NO\n";
		return ;
	}
	if(s[0]!='1'||s[1]!='0')
	{
		cout<<"NO\n";
		return ;
	}
	if(s[2]=='0'||(s[2]=='1'&&s.size()==3)) 
	{
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
