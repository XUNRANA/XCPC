#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,x,y,mx;
void solve()
{
	cin>>n>>m;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[t]++;
	}
	mx=0;
	for(auto i:mp)
	{
		x=i.first;
		y=i.second;
		mx=max(mx,x*min(y,m/x));
		if(mp.count(x+1))
		{
			for(int i=1;i<=y&&x*i<=m;i++) mx=max(mx,x*i+(x+1)*min(mp[x+1],(m-x*i)/(x+1)));
		}
	}
	cout<<mx<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
