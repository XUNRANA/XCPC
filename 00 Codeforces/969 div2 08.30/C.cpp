#include <bits/stdc++.h>
using namespace std;
int n,a,b,g;
int c[100010];
void solve()
{
	cin>>n>>a>>b;
	int g=__gcd(a,b);
	for(int i=1;i<=n;i++) cin>>c[i],c[i]%=g;
	sort(c+1,c+1+n);
	int ans=c[n]-c[1];
	for(int i=2;i<=n;i++) ans=min(ans,c[i-1]+g-c[i]);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
