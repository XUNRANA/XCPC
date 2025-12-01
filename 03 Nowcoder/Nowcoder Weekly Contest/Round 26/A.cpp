#include <bits/stdc++.h>
using namespace std;
int n,k,t,ans;
void solve()
{
	cin>>n>>k;
	map<int,int>mp;
	while(n--)
	{
		cin>>t;
		mp[t%k]++;
	}
	for(auto i:mp) ans=max(ans,i.second);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

