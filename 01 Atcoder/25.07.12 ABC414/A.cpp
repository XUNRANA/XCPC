#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,l,l1,r,r1;
    cin>>n>>l>>r;
    int ans=0;
    while(n--)
    {
        cin>>l1>>r1;
        if(l1<=l&&r1>=r) ans++;
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}