#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k,b,c;
	cin>>n>>k;
	map<int,int>mp;
	for(int i=1;i<=k;i++) 
	{
		cin>>b>>c;
		mp[b]+=c;
	}
	vector<int>v;
	for(auto i:mp) v.push_back(i.second);
	sort(v.begin(),v.end(),greater<int>());
	int ans=0;
	for(int i=0;i<min((int)v.size(),n);i++) ans+=v[i];
	cout<<ans<<"\n"; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
