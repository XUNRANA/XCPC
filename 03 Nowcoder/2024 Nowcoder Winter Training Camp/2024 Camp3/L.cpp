#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,t;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t==6&&mp.count(3)) ans+=mp[3];
		if(t==2&&mp.count(7)) ans+=mp[7];
		if(t==8&&mp.count(10)) ans+=mp[10];
		if(t==3&&mp.count(6)) ans+=mp[6];
		if(t==7&&mp.count(2)) ans+=mp[2];
		if(t==10&&mp.count(8)) ans+=mp[8];
		mp[t]++;
	}
	cout<<ans; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
