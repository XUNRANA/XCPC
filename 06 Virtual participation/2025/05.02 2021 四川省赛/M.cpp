#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve () {
    ll n, k, x, p0; cin >> n >> k >> x >> p0;
    vector<ll> s(n + 1), t(k + 1), p(k + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= k; i++) cin >> t[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    int res = 0;
    ll mn = ceil(1.0 * x / p0);
    for (int i = 1; i <= k; i++) {
        mn = min(mn, ll(ceil(1.0 * x / (p[i] - t[i]))));
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] >= mn) res++;
    }
    cout << res << '\n';
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    solve();
    return 0;
}