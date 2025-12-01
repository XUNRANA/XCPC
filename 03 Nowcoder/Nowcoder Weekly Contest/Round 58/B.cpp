#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]<s[i+1])
		{
			cout<<"YES\n";
			return  ;
		}
	}
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

