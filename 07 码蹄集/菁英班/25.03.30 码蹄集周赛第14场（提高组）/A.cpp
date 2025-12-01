#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=1;
    for(int i=1;i<=n;i++)
    {
        int ans=1;
        int j=i+1;
        while(j<=n&&a[j]<=a[j-1]) j++,ans++;
        j=i-1;
        while(j>=1&&a[j]<=a[j+1]) j--,ans++;
        // cout<<i<<" "<<ans<<"\n";
        res=max(res,ans);
    }
    cout<<res<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}