#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[1010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
        int mi=a[i];
        int mx=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>=mi-1&&a[j]<=mx+1) 
            {
                ans=min(ans,j-i-1);
            }
            mi=min(mi,a[j]);
            mx=max(mx,a[j]);
        }
    } 
    for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
    
    for(int i=1;i<=n;i++)
    {
        int mi=a[i];
        int mx=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>=mi-1&&a[j]<=mx+1) 
            {
                ans=min(ans,j-i-1);
            }
            mi=min(mi,a[j]);
            mx=max(mx,a[j]);
        }
    } 
    
    
    if(ans==1e9) ans=-1;
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