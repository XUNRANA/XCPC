#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int a[200010];
void solve() 
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=1,r;
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]*2<=a[i-1])
        {
            r=i-1;
            ans+=max((r-l+1)-x,0ll);
            l=i;
        }
    }
    r=n;
    ans+=max((r-l+1)-x,0ll);
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}