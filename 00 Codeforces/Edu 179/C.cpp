#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    int ans=1e18;
    int cnt=1;

    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            cnt++;
        }
        else 
        {
            ans=min(ans,a[i-1]*(n-cnt));
            cnt=1;
        }
    }
    ans=min(ans,a[n]*(n-cnt));
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