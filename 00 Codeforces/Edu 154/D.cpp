#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];

	//..-1...0....1...
	int c0=0,c1=0;
	for(int i=1;i<n;i++) if(a[i]>=a[i+1]) c1++;
	int ans=c1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=a[i-1]) c0++;

		if(a[i]>=a[i+1]) c1--;
		ans=min(ans,c1+c0);
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
