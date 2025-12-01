#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l,r,ans;
void solve()
{
	cin>>l>>r;
	if(l*2>r) ans=0;
	else 
	{
		ans=r/2-l+1;
		if((r-2*l)%2==0) ans+=(r-2*l+2)*((r-2*l)/2);
		else ans+=(r-2*l+1)*((r-2*l+1)/2);
	}
	cout<<ans<<'\n';
}
signed main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
