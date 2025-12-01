#include <bits/stdc++.h>
using namespace std;
int n,a[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2&&abs(a[1]-a[2])>=2) cout<<"YES\n";
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

