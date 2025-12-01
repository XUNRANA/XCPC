#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int n,m;
	cin>>n>>m;
	if(m==0) cout<<n<<"\n";
	else
	{
		int l=max(0ll,n-m),r=n+m,len=r-l+1;
		int ans=l|r;
		for(int i=0;i>=0;i++)
		{
			if((1ll<<i)<len) ans|=(1ll<<i);
			else break;
		}
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

