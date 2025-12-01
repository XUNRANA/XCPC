#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(!x) s++;
        else 
        {
            ans+=(s+1)/(k+1);
            s=0;
        }
    }
    ans+=(s+1)/(k+1);
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
