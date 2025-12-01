#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a,b;
    cin>>a>>b;
    if(a&1)
    {
        if(a>b) cout<<"1\n";
        else cout<<"2\n";
    }
    else
    {
        if(b>a) cout<<"1\n";
        else cout<<"2\n";
    }
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