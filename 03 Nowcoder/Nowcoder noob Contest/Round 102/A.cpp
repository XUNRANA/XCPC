#include <bits/stdc++.h>
using namespace std;
int n,k,a[110];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int t=1;
	for(int i=1;i<=n;i++) if(a[i]==t) t++;
	if(t>k) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
