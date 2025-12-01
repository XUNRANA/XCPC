#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,x[200010],y[200010];
int c[2];
void solve()
{
	ans=0;
	c[1]=c[0]=0;
	cin>>n;
	map<pair<int,int>,int>mp;
	for(int i=1;i<=n;i++) 
	{
		cin>>x[i]>>y[i];
		c[y[i]]++;
		mp[{x[i],y[i]}]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp.count({x[i],y[i]^1})) ans+=c[y[i]]-1;
		if(mp.count({x[i]-1,y[i]^1})&&mp.count({x[i]+1,y[i]^1})) ans++;
	}
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
