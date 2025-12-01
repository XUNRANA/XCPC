#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,ans=0;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		if(s.size()==3&&s[1]==s[2]&&s[0]!=s[1]) ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
