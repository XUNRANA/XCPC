#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],b[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(b+1,b+1+m);
	a[1]=min(a[1],b[1]-a[1]);
	for(int i=2;i<=n;i++)
	{
		int it=lower_bound(b+1,b+1+m,a[i-1]+a[i])-b;
		if(it==m+1&&a[i]<a[i-1])
		{
			cout<<"NO\n";
			return ;
		}
		if(it!=m+1)
		{
			if(a[i]<a[i-1]) a[i]=b[it]-a[i];
			else a[i]=min(a[i],b[it]-a[i]);
		}
	}
	cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
