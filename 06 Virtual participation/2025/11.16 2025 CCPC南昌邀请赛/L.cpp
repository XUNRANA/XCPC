#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b;
    cin>>a>>b;
    if(a==30||(a>=21&&a-b>=2)) cout<<"Alice\n";
    else if(b==30||(b>=21&&b-a>=2)) cout<<"Bob\n";
    else cout<<"Underway\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>T;
    while(T--) solve();
}