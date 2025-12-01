#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int mx = 0, id = 0;
    auto dfs1 = [&](auto&&self, int u, int fa, int len) -> void {
        if (mx < len) {
            mx = len;
            id = u;
        }
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u, len + 1);
        }
    };
    dfs1(dfs1, 1, 0, 0);
    dfs1(dfs1, id, 0, 0);
    cout << mx << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}