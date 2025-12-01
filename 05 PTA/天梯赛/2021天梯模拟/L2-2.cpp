#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,a[100010];
void solve()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int j=lower_bound(a+1,a+1+n,p+a[i])-a;
		int j1=upper_bound(a+1,a+1+n,abs(p-a[i]))-a;
		j--;
		j1=max(j1,i+1);
		ans+=max(j-j1+1,0ll);
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
