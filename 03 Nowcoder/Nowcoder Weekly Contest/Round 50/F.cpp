#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int ck(int x)
{
	int t=sqrt(x);
	return t*t==x;
}
void solve()
{
	cin>>n;
	ans=0;
	for(int i=0;i*i<=n-i*i;i++) if(ck(n-i*i)) ans=__gcd(ans,__gcd(n,2ll*(n-i*i)));
	if(ans==0) cout<<"inf\n";
	else cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
