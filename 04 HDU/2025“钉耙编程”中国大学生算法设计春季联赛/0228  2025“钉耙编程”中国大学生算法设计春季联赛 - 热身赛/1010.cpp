#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
void solve()
{
    int ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        ans+=abs(a[i])*(n-i+1);
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
