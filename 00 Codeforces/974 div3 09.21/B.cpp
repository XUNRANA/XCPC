#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k,l,r,cnt;
	cin>>n>>k;
	l=n-k+1,r=n;
	cnt=(r-l+1)/2;
	if((k&1)&&(n&1)) cnt++;
	if(cnt&1) cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
