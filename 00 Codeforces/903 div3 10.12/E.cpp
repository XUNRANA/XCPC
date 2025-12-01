#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200010],d[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],d[i]=2*n;
	for(int i=1;i<=n;i++)
	{
		d[i]=min(d[i],d[i-1]+1);
		if(a[i]+i>n) continue;
		d[a[i]+i]=min(d[a[i]+i],d[i-1]);
	}
	cout<<d[n]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
