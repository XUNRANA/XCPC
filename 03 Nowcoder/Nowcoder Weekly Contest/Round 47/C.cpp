#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],mx,s,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i],mx=max(mx,a[i]);
    if(n==2&&a[1]==a[2]) cout<<"0\n";
	else if(mx>=s-mx) cout<<"1\n";
	else if(s&1) cout<<n<<"\n";
    else
    {
        for(int i=1;i<=n;i++) if(a[i]>1) ans++;
        cout<<ans<<"\n";
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
