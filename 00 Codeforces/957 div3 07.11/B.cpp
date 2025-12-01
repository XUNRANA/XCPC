#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,ans,mx,t,k;
	cin>>n>>k;
	ans=mx=0;
	map<int,int>mp;
	for(int i=1;i<=k;i++)
	{
		cin>>t;
		mx=max(mx,t);
		mp[t]++;
	}
	for(auto i:mp) ans+=(2*i.first-1)*i.second;
	ans-=2*mx-1;
	cout<<ans<<"\n"; 
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
