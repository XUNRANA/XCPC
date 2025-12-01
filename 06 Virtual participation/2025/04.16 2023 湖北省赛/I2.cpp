#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7;

void solve() {
    int n; cin >> n;

    vector<ll> a(n + 1);
    ll lc = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll g = __gcd(lc, a[i]);
        lc = lc / g * a[i];
    }

    vector<ll> f;
    ll x = 1, y = lc;
    for (int i = 2; i <= N; i++) {
        while (lc % i == 0) {
            f.push_back(i);
            lc /= i;
        }
    }
    cout << 26138699LL * 26138700 / 2 << '\n';
    ll res = 1e18;
    int m = 1 << f.size();

    for (int i = 0; i < m; i++) {
        ll X = 1, Y = y;
        for (int j = 0; j < f.size(); j++) {
            if ((i >> j) & 1) {
                X *= f[j];
                Y /= f[j];
                ll l = X - 1, r = X + 1;
                if (l % Y == 0) {
                    ll k = l / Y;
                    if (!(k & 1)) res = min(X - 1, res);
                } 
                if (r % Y == 0) {
                    ll k = r / Y;
                    if (!(k & 1)) res = min(X, res);
                }
            }
        }
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}