#include <bits/stdc++.h>
using namespace std;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define int long long
int mx[4];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<4;i++) mx[i]=-1e18;
	for(int i=1;i<=n;i++) 
	{
		int x,y;
		cin>>x>>y;
		mx[0]=max(mx[0],x+y);
		mx[1]=max(mx[1],-x+y);
		mx[2]=max(mx[2],-x-y);
		mx[3]=max(mx[3],x-y);
	}
	
	int ans=1e18;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int res=0;
		res=max(res,mx[0]-x-y);
		res=max(res,mx[1]+x-y);
		res=max(res,mx[2]+x+y);
		res=max(res,mx[3]-x+y);
		ans=min(ans,res);
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
