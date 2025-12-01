#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() 
{
    int n, m; cin >> n >> m;
    int res = 0;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> r(n + 1, 1e6), c(m + 1, 1e6);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            r[i] = min(r[i], a[i][j]);
            c[j] = min(c[j], a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res += (a[i][j] == r[i] and a[i][j] == c[j]);
        }
    }
    cout << res << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
