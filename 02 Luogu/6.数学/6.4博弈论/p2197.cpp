#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,t;
void solve()
{

	
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans^=t;
	}
	if(ans) cout<<"Yes\n";
	else cout<<"No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
