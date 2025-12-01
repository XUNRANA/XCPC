#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans;
void solve()
{
	cin>>n;
	while(n--)
	{
		cin>>t;
		if(t!=1) ans++;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
