#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,l,r;
void solve()
{
	ans=0;
	cin>>l>>r;
	if((r-l+1)&1)
	{
		ans^=l;
		l++;
	}
	int c=(r-l+1)/2;
	if(l&1)
	{
		c--;
        ans^=l^r;
	}
    
	if(c&1) ans^=1;
    else ans^=0;
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
