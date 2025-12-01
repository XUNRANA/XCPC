#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

// 快速计算单个测试用例
void solve() {
    ll n, k, m, T;
    cin >> n >> k >> m >> T;

    ld E = 0;

    for (int i = 1; i <= T; i++) {
        ll g = __gcd(i + 1ll, n);
        ld Ci = floor(((ld)k * g) / (ld)n);
        E += m * (k - Ci) / (n - 1);
    }
    // cout << E << endl;
    cout << (ll)(ceil(E / T)) << endl;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    while (Q--) {
        solve();
    }

    return 0;
}
