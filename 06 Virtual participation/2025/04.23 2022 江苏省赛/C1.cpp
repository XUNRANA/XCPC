#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() 
{
    int n, p, q; cin >> n >> q >> p;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        int x; cin >> x;
        if (x > p) {
            cout << "Noob" << '\n';
            continue;;
        }
        vector<ll> f(n + 1);
        ll res = -(1LL << 60LL);
        for (int i = 1; i <= n; i++) {
            if (i % x) continue;
            ll t = -(1LL << 60LL);
            for (int l = 1; i - l * x >= 0 and l * x <= p; l++) {
                t = max(t, f[i - l * x] + a[i]);
            }
            f[i] = t;
            if (i + p / x * x > n) res = max(res, f[i]);
            // cout << f[i] << ' ';
        }
        cout << res << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--)
    solve();
    return 0;
}
