#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    if(a[i])
    {
        if(i==1) ans=a[i]-1;
        else ans=a[i];
        for(int j=i+1;j<=n;j++) ans+=max(a[j]-a[j-1],0ll);
        break;
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
    return 0;
}