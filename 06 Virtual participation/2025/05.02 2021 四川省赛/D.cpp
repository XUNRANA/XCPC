#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define int long long

int mp[3][3];

void solve () {
    vector<int> a(3), b(3);
    int res = 0;
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    for (int i = 0; i < 3; i++) {
        int x = min(b[i], a[(i - 1 + 3) % 3]);
        b[i] -= x;
        a[(i - 1 + 3) % 3] -= x;
        res += x;
    }
    for (int i = 0; i < 3; i++) {
        int x = min(a[i], b[i]);
        a[i] -= x;
        b[i] -= x;
    }
    for (int i = 0; i < 3; i++) {
        res -= b[i];
    }
    cout << res << '\n';
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mp[0][1] = 1;
    mp[0][2] = -1;
    mp[1][0] = -1;
    mp[1][2] = 1;
    mp[2][0] = 1;
    mp[2][1] = -1;
    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}