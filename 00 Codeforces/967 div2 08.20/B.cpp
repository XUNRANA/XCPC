#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];

void solve()
{
	cin>>n;
	if(n&1)
	{
		for(int i=1;i<=n;i++) a[i]=i;
		for(int i=n/2+1,j=n;i<j;i++,j--) swap(a[i],a[j]);
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	else cout<<"-1\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
