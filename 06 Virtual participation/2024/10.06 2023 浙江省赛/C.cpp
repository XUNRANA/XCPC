#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[100010],b[100010],ans;
void solve()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++) ans+=a[i]>=x;
	for(int i=1;i<=m;i++) ans+=b[i]<=x;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
