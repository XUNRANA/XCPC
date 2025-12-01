#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
	cin>>n;
	int mi=100;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) mi=min(mi,a[i]);
	cout<<mi+a[n]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
