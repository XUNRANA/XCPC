#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,m;
	cin>>n>>m;
	int ans=0;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			mx=max(mx,x);
		}
		if(f) cout<<" ";
		cout<<mx;
		f=1;
		ans=max(ans,mx);
	}
	cout<<"\n";
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
