#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int n,t,ans=0;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>t,mp[t]++;
	for(auto i:mp) ans=max(ans,i.second);
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
