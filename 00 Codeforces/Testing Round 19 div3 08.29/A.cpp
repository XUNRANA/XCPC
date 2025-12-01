#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	s=a[1];
	for(int i=2;i<=n;i++)
	if(i&1) s+=a[i];
	else s-=a[i];
	cout<<s<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
