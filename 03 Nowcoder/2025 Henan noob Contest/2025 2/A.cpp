#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;)
    {
        int x=n/i;
        int r=n/x;
        ans+=(r-i+1)*x;
        i=r+1;
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

// 1
// 3
// 5
// 8
// 10
// 14
// 16
// 20
// 23
// 27
// 29
// 35
// 37
// 41
// 45
// 50
// 52
// 58
// 60
// 66
