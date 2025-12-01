#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],k,ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        k=min({a[i]/3,a[i-1]/2,a[i-2]});
        ans+=5*k;
        a[i]-=3*k;
        a[i-1]-=2*k;
        a[i-2]-=k;
        ans+=a[i];
    }
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

