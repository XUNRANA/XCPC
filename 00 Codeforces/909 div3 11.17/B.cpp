#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mx,mi,t1,a[150010],ans;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
	{

		if(n%i==0)
		{
			mx=0;
			mi=1e18;
			for(int j=i;j<=n;j+=i)
			{
				mx=max(mx,a[j]-a[j-i]);
				mi=min(mi,a[j]-a[j-i]);
			}
		//	cout<<mx<<" "<<mi<<"\n";
			ans=max(mx-mi,ans);
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
