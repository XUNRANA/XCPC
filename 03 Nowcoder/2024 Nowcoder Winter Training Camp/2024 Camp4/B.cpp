#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans+=t-1;
	}
	if(ans&1) cout<<"gui\n";
	else cout<<"sweet\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
