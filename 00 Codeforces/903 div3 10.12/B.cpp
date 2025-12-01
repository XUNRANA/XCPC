#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[4],ans,g;
void solve()
{
	for(int i=1;i<=3;i++) cin>>a[i];
	sort(a+1,a+1+3);
	if(a[1]==a[3])
	{
		cout<<"YES\n";
		return ;
	}
	ans=0;
	g=0;
	g=__gcd(a[1],a[2]);
	g=__gcd(g,a[3]);
	for(int i=1;i<=3;i++)
	if(a[i]!=g) ans+=a[i]/g-1;
	if(ans<=3) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
