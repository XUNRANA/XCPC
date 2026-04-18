#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]; 
    sort(a+1,a+1+n);
    int ans=0;
    int mx=1e9;
    for(int i=1;i<=n;i++) 
    {
        mx=min(mx,a[i]);
        ans+=a[i];
    }
    ans-=mx;
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