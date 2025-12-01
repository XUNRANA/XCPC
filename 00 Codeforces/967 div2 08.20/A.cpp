#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,t;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[t]++;
	}
	int mx=0;
	for(auto i:mp)
	{
		mx=max(mx,i.second);
	}
	cout<<n-mx<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
