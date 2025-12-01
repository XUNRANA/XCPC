#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x[200010],r[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>r[i];
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		for(int j=-r[i];j<=r[i];j++)
		{
			int nx=x[i]+j;
			int ny=sqrtl(r[i]*r[i]-j*j);
			if(mp.count(nx)) mp[nx]=max(mp[nx],ny);
			else mp[nx]=ny;
		}
	}
	int ans=0;
	for(auto i:mp) ans+=i.second*2+1;
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

