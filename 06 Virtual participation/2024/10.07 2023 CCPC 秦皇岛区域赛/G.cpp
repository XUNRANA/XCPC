#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100010],b[100010],ans;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<n;i++) ans+=abs(a[i+1]-a[i]);
	for(int i=1;i<m;i++) ans+=abs(b[i+1]-b[i]);
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
