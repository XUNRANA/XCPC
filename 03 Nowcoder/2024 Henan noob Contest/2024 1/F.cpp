#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,res,n,a[200010];
void solve()
{
	cin>>n;
	res=0;
	for(int i=1;i<=n;i++) cin>>a[i],res^=a[i];
	for(int i=1;i<=n;i++)
	{
		int x=n/i;
		for(int j=1;j<=x;j++) 
		{
			ans=max(ans,res^a[i]^(a[i]+j));
			ans=max(ans,res^a[i]^(a[i]*j));
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
