#include <bits/stdc++.h>
using namespace std;
#define int long long
string fx(string s)
{
	vector<int>f(26,-1);
	set<int>st;
	int n=s.size();
	for(int i=n-1;i>=0;i--)
	{
		if(f[s[i]-'a']==-1) f[s[i]-'a']=st.size();
		st.insert(s[i]);
	}
	string t;
	for(int i=0;i<n;i++) t+=char(f[s[i]-'a']+'a');
	return t;
}
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	vector<string>vt;
	for(int i=1;i<=n;i++) vt.push_back(fx(s.substr(0,i)));
	sort(vt.begin(),vt.end());
	cout<<vt.back()<<"\n";
//	for(auto i:vt) cout<<i<<" ";
//	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
