#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() 
{
    for (int k = 0; k <= 1; k++) 
    {
        for (ll x = 1, y = 2; y <= 20; x++, y++) {
            bool flag = 1;
            for (ll i = x - k; i < x; i++) {
                if (y % i == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << k << ' ' << x << ' ' << y << '\n';
                break;
            }
        }
    }
    cout << 1;
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
