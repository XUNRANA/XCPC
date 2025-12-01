#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,x,y,z,c1,c2,c3,mx,a[200010];
void solve()
{
	cin>>n>>m;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		mp[a[i]]+=t;
	}
	mx=0;
	
	for(auto i:mp)
	{
		x=i.first;
		y=i.second;
		mx=max(mx,x*min(y,m/x));
		if(mp.count(x+1))
		{
			c1=min(y,m/x);
			c2=min(mp[x+1],(m-x*c1)/(x+1));
			c3=min(c1,max(0ll,mp[x+1]-c2));
			mx=max(mx,min(m,c1*x+c2*(x+1)+c3));
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
