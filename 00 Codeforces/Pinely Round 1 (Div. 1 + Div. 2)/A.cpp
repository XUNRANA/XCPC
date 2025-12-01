#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b>=n)
    {
        if(a==n&&b==n) cout<<"Yes\n";
        else cout<<"No\n";
    }
    else if((n-a-b)>1) cout<<"Yes\n";
    else cout<<"No\n";
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