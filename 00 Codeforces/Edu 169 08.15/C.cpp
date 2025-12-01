#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],sa,sb,k1;
void solve()
{
	sa=sb=k1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i-=2)
	{
		sa+=a[i];
		if(i-1>=1) 
		{
			sb+=a[i-1];
			k1+=a[i]-a[i-1];
		}
	}
	if(sb+min(k,k1)>=sa) cout<<"0\n";
	else cout<<sa-sb-min(k,k1)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
