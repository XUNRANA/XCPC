#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sa,sai,saii,t,ans=1e18;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>t;
        sa+=t;
        sai+=t*i;
        saii+=i*i*t;
    }
    for(int i=1;i<=n;i++) ans=min(ans,i*i*sa-2*i*sai+saii);
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--) solve();
}