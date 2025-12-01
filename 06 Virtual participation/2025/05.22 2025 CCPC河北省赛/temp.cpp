#include <bits/stdc++.h>
using namespace std;
// #define int long long

class LCA {
public:
    vector<int> lo2, d;
    vector<array<int, 22>> f;
    vector<vector<int>>& g;

    void dfs(int u, int fa) {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i <= lo2[d[u]]; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (int v: g[u]) {
            dfs(v, u);
        }
    }

    LCA(int N, vector<vector<int>>& grp, int root): g(grp), lo2(N + 1), d(N + 1), f(N + 1) {
        for (int i = 2; i < N; i++) lo2[i] = lo2[i >> 1] + 1;
        dfs(root, 0);
    }
    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        while (d[u] > d[v]) u = f[u][lo2[d[u] - d[v]]];
        if (u == v) return u;
        for (int i = lo2[d[u]]; i >= 0; i--) {
            if (f[u][i] != f[v][i]) {
                u = f[u][i], v = f[v][i];
            }
        }
        return f[u][0];
    }
};

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<set<int>> vis(1e6 + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g1(n + 2), g2(n + 2);
    for (int i = 2; i <= n; i++) {
        int fa; cin >> fa;
        g1[fa].push_back(i);
    }

    auto dfs1 = [&](auto&&self, int u) -> void {
        if (vis[a[u] + 1].empty()) {
            g2[n + 1].push_back(u);
        } else {
            g2[*vis[a[u] + 1].begin()].push_back(u);
        }
        vis[a[u]].insert(u);
        for (int v: g1[u]) {
            self(self, v);
        }
        vis[a[u]].erase(u);
    };
    dfs1(dfs1, 1);
    LCA tree(n + 2, g2, n + 1);
    int q; cin >> q;
    while (q--) {
        int s, t; cin >> s >> t;
        auto fa = tree.lca(s, t);
        int res = tree.d[s] - tree.d[fa];
        if (fa == t) res++;
        cout << res << '\n';
    }
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
