#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[2010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2)
	{
		if(n==1) cout<<"1\n";
		else cout<<a[2]-a[1]<<"\n";
		return ;
	}
	
	if(n&1)
	{
		int ans=1e18;
		for(int i=1;i<=n;i+=2) 
		{
			vector<int>b;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				b.push_back(a[j]);
			}
			int res=0;
			for(int i=0;i<b.size();i+=2) res=max(res,b[i+1]-b[i]);
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i+=2) ans=max(ans,a[i+1]-a[i]);
		cout<<ans<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
