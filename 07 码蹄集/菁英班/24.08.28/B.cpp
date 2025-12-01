#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,t,mx,ans;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mx=max(mx,t);
		mp[t]++;
	}
	ans=1;
	for(auto i:mp)
	{
		if(i.first==mx) continue;
		ans=ans*(i.second+1)%P;
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
