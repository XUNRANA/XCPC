#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	int ans=0;
	cin>>s;
	s=" "+s;
	vector<int>dp(s.size()+1);
	for(int i=2;i<s.size();i++)
	{
		if(s[i]==s[i-1]) dp[i]=dp[i-2]+2;
		ans=max(ans,dp[i]);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

