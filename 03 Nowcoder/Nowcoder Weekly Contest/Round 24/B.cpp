#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,ans;
	cin>>n;
	ans=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
            if(n/i!=i) ans=min(ans,n/i);
		}
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

