#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;
void solve()
{
	ans=0;
	cin>>n;
	map<pair<int,int>,int>mp[3];
	map<tuple<int,int,int>,int>cnt;
	cin>>a[1]>>a[2];
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		
		ans+=mp[0][{a[i-2],a[i-1]}]-cnt[make_tuple(a[i-2],a[i-1],a[i])];
		mp[0][{a[i-2],a[i-1]}]++;
		
		ans+=mp[1][{a[i-2],a[i]}]-cnt[make_tuple(a[i-2],a[i-1],a[i])];
		mp[1][{a[i-2],a[i]}]++;
		
		ans+=mp[2][{a[i-1],a[i]}]-cnt[make_tuple(a[i-2],a[i-1],a[i])];
		mp[2][{a[i-1],a[i]}]++;
		cnt[make_tuple(a[i-2],a[i-1],a[i])]++;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
