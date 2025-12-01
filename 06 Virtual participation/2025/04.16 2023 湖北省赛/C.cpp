#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6;

void solve() 
{
    int n,m;
    cin>>n>>m;
    
    if(n==1)
    {
        cout<<m/2+1<<"\n";
    }
    else if(m==1)
    {
        cout<<n/2+1<<"\n";
    }
    else 
    {
        if(n>m) swap(n,m);
        int t=m-n;
        cout<<n+(t+1)/2<<"\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}