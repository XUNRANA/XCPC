#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};
void solve()
{
	int n,m,a,b,mx=0;
	cin>>n>>m;
	vector<int>f(n);
	for(int i=1;i<=m;i++)
	{
		int t=rng();
		cin>>a>>b;
		a--;
		b--;
		f[a]^=t;
		f[b]^=t;
	}
	map<int,int>mp;
	for(int i=1;i<n;i++) f[i]^=f[i-1];
	for(int i=0;i<n;i++) mx=max(mx,++mp[f[i]]);
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
