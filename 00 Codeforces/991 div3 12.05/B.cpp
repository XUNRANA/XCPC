#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],n,s0,s1,c0,c1;
void solve()
{
	cin>>n;
	s0=s1=c0=c1=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i&1) s1+=a[i],c1++;
		else s0+=a[i],c0++;
	}
	if(s1%c1==0&&s0%c0==0&&s1/c1==s0/c0) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
