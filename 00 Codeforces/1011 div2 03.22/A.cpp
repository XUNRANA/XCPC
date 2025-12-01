#include <bits/stdc++.h>
using namespace std;
#define int long long
string fx(string s)
{
	string ans="";
	for(int i=s.size()-1;i>=0;i--) ans+=s[i];
	return ans;
}
void solve()
{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	string t=s;
	sort(t.begin(),t.end());
	if(t[0]==t[n-1]) cout<<"NO\n";
	else
	{
		if(s<fx(s)) cout<<"YES\n";
		else if(k>=1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
