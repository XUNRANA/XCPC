#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353




int a[200010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=0;
    for(int i=0;i<m;i++)
    {
        int mx=i^a[1];
        for(int j=2;j<=n;j++) mx=min(mx,i^a[j]);
        ans+=mx;
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
