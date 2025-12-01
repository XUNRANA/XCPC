#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,suf[200010];
string s;
void solve()
{
	cin>>n>>s;
	s=" "+s;
	map<int,int>mp;
	suf[n+1]=0; 
	for(int i=n;i>=1;i--)
	{
		mp[s[i]-'a']++;
		if(mp[s[i]-'a']==1) suf[i]=1;
		suf[i]+=suf[i+1];
	}
	ans=mp.size();
	set<char>st;
	for(int i=1;i<=n;i++) 
	{
		if(st.count(s[i])) continue;
		st.insert(s[i]);
		ans+=suf[i+1];
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
