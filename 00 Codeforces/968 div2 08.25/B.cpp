#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<a[n/2+1]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
