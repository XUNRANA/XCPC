#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if((i/2)&1) ans-=x;
        else ans+=x;
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