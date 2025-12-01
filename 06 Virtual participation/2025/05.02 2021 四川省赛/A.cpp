#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve () {
    int k; cin >> k;
    int res = 0;
    for (int x = 1; x <= 6; x++) {
        for (int y = x; y <= 6; y++) {
            res += ((x + y) == k);
        }
    }
    cout << res << '\n';
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}