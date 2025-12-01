#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int a[1000010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=a[n],ans=0;
    for(int i=n-1;i>=1;i--)
    {
        ans=(ans+s*a[i]%P*(s+a[i])%P)%P;
        s=(s+a[i])%P;
    }
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
