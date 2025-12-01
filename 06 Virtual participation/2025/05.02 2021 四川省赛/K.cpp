#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve () {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        for(int j=i;j<=n;j+=k) cout<<j<<" ";
    }
    cout<<"\n";
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    solve();
    return 0;
}