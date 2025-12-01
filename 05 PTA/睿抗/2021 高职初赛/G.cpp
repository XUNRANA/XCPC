#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(string a,string b)
{
	return a>b;
}
void solve()
{
	int n,m;
	cin>>n;
	set<string>st;
	while(n--)
	{
		string s;
		cin>>s;
		st.insert(s);
	}
	cin>>m;
	while(m--)
	{
		string s;
		cin>>s;
		st.erase(s);
	}
	vector<string>a;
	for(auto i:st) a.push_back(i);
	sort(a.begin(),a.end(),cmp);
	for(auto i:a) cout<<i<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
