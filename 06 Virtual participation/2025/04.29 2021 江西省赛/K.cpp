#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() 
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++) ans+=m*i*i;
    cout<<ans<<"\n";

}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
