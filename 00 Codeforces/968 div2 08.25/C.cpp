#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[200010];
void solve()
{
	int n;
	string s;
	map<char,int>mp;
	cin>>n>>s;
	for(auto i:s) mp[i]++;
	vector<pair<int,int>>v;
	for(auto i:mp) v.push_back({i.second,i.first-'a'});
	sort(v.begin(),v.end());
	for(int i=1,j=v.size()-1;i;i+=2) 
	{
		if(i>n) i=2;
		while(!v[j].first) j--;
		ans[i]=v[j].second;
		v[j].first--;
		if(j==0&&v[0].first==0) break;
	}
	for(int i=1;i<=n;i++) cout<<char('a'+ans[i]);
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
