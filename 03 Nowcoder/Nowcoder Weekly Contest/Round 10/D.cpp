#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int n,a[1010],ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) ans=(ans+(a[i]+1)*a[i]/2%P)%P;
    for(int i=1;i<=n;i++)
    {
        int j=1;
        while(i-j>=1&&i+j<=n&&a[i-j]==a[i+j]) 
        {
            ans=(ans+a[i+j])%P;
            j++;
        }
        ans=(ans+min(a[i-j],a[i+j]))%P;
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
