#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],s;
void solve()
{
	cin>>n;
	s=0;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	sort(a+1,a+1+n);
	if(n==1||n==2) cout<<"-1\n";
	else cout<<max(0ll,a[n/2+1]*2*n-s+1)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
