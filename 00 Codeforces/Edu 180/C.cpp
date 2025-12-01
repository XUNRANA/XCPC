#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[5010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);

    int res=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            //最大值和次大值
            int ans=a[i]+a[j];
            if(i==n) ans-=2*a[i];
            else ans-=max(a[n],2*a[i]);
            // cout<<i<<" "<<j<<" "<<ans<<"?\n";
            res+=j-min(j,upper_bound(a+1,a+1+n,-ans)-a);
        }
    }
    cout<<res<<"\n";

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