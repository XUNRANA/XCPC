#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[11];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(a[i]>x) ans+=a[i]-x;
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
}