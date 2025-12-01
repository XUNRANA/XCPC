#include <bits/stdc++.h>
using namespace std;
#define int long long
int p,m,ans;
void solve()
{
	cin>>p>>m;
	ans=m/p;
	
	for(int i=m/p;i<=(m+p-1)/p;i++)
	{
		if(((p-1)^(i*p+1))<=m) ans++;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
