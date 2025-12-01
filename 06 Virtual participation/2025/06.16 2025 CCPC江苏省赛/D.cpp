#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int val=1;
    int ans=0;
    int x;
    cin>>x;
    while(x)
    {
        ans+=(x%10)*val;
        val*=2;
        x/=10;
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