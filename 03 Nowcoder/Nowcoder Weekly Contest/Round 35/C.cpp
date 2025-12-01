#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010];
void solve()
{
    double ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
    for(int i=1,j=1;i<=n;i++)
    {
        while(a[i]-a[j]>k) j++;
        ans=max(ans,1.0*(i-j+1)/n);
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

