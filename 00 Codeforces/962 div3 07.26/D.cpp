#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,ans,x;
void solve()
{
	ans=0;
	cin>>n>>x;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j+i<=x&&i*j<=n;j++)
		{
			int k=min(x-i-j,(n-i*j)/(i+j));
			ans+=k;
		}
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
