#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,q,tc,a[100010],m;
void solve()
{
	cin>>n>>q>>tc;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);	
	for(int i=1;i<=n;i++) a[i]+=a[i-1];	
	while(q--)
	{
		cin>>m;
		cout<<a[max(0ll,n-m/tc)]+tc<<"\n";
	}

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
