#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	if(s[0]!='1'||s[s.size()-1]=='9') cout<<"NO\n";
	else
	{
		for(int i=1;i<s.size()-1;i++) 
		if(s[i]=='0') 
		{
			cout<<"NO\n";
			return ;
		}
		cout<<"YES\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
