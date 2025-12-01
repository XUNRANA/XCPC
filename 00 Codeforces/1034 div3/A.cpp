#include <bits/stdc++.h>
using namespace std;
#define int long long

// 0 1 2 3
// 0 1 2 3 
void solve()
{
    int n;
    cin>>n;
    if(n%4==0) cout<<"Bob\n";
    else cout<<"Alice\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}