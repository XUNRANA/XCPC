#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s,a;
void solve()
{
	cin>>n>>k;
	s=0;
	for(int i=1;i<=n;i++) cin>>a,s+=a;
	cout<<s*k<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
