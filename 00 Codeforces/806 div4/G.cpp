#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010];
void solve() 
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int v=2;
        int s1=0;
        for(int j=i;j<=n;j++)
        {
            s1+=a[j]/v;
            v*=2;
            if(v>1e9) break;
        }
        ans=max(ans,s+s1);
        s+=a[i]-k;
    }
    ans=max(ans,s);
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