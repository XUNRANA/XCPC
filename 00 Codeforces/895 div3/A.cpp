#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int t=(abs(a-b)+1)/2;
    cout<<(t+c-1)/c<<"\n";
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