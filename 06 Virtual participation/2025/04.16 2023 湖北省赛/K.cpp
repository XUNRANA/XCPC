#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
ll A[N];

const ll mod = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return res;
}

ll inv(ll a) {
    return qpow(a, mod - 2);
}

ll C(ll n, ll m) {
    return A[n] * inv(A[m]) % mod * inv(A[n - m]) % mod;
}

ll p[N];

void solve() {
    int n, m; cin >> n >> m;
    A[0] = 1;
    for (int i = 1; i < N; i++) {
        A[i] = A[i - 1] * i % mod;
        if (i <= m) { 
            p[i] = (m - i) * inv(m) % mod;
        }
    }
    auto dfs = [&](auto&&self, int i, int n) -> ll {
        if (n == 0) return 1;
        ll res = 0;
        for (int j = 0; j < n; j++) {
            res = (res + C(n, j) * qpow(m - i, n - j) % mod * self(self, i, j) % mod) % mod;
        }
        return res * inv(qpow(m, n) - 1) % mod;
    };
    for (int i = 1; i <= m; i++) {
        cout << dfs(dfs, i, n) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}