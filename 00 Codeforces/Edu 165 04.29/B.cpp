#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	long long s1=0,ans=0;
	
	int i=0;
	while(s[i]=='0'&&i<s.size()) i++;
	for(;i<s.size();i++)
	{
		if(s[i]=='1') s1++;
		else ans+=s1+1;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve(); 
}
