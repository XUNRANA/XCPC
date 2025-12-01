#include <bits/stdc++.h>
using namespace std;
#define int long long


int p[300010];
int s[300010];
int a[300010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    for(int i=n;i>=1;i--) s[i]=max(s[i+1],a[i]+i);
    for(int i=1;i<=n;i++) p[i]=max(p[i-1],a[i]-i);

    int a1=0,a2=0;
    for(int i=1;i<=n;i++) a1=max(a1,a[i]+i-1);
    for(int i=1;i<=n;i++) a2=max(a2,a[i]+n-i);
    // cout<<a1<<" "<<a2<<"\n";

    int ans=min(a1,a2);
    for(int i=2;i<=n-1;i++) 
    {
        int res=a[i];
        res=max(res,p[i-1]+i+n-i);
        res=max(res,s[i+1]-i+i-1);


        // cout<<p[i-1]+i+n-i<<" :";
        // cout<<s[i+1]-i+i-1<<"\n";

        // cout<<i<<" "<<res<<"\n";

        
        ans=min(ans,res);
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
    return 0;
}