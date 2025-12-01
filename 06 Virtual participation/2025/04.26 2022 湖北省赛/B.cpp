#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    int g=__gcd(x,y);
    x/=g;
    y/=g;
    x+=y;
    if(1ll<<__lg(x)==x)
    {
        cout<<__lg(x)+1<<"\n";
    }
    else cout<<"-1\n";
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