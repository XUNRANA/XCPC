#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve()
{
    int n, m; cin >> n >> m;
    vector<string> s(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int cnt = 0;
    vector<int> vis;
    int ra, rb, rc, ca, cb, cc;
    cin >> ra >> rb >> rc >> ca >> cb >> cc;
    bool flag = 0;
    auto dfs = [&](auto&&self, int x) -> void {
        if (x > n) {
            if (vis.size() > 13 or vis.size() < 10 or flag) return;
            vector<int> a(m + 1);
            for (auto u: vis) {
                for (int i = 1; i <= m; i++) {
                    if (s[i][u] == '1') a[i]++;
                }
            }
            sort(a.begin(), a.end());
            reverse(a.begin() + 1, a.end());
            if (a[ra] == ca and a[rb] == cb and a[rc] == cc) {
                cout << vis.size() << '\n';
                for (auto u: vis) cout << u << ' ';
                flag = 1;
                return;
            }
        }
        if (flag) return;
        vis.push_back(x);
        self(self, x + 1);
        vis.pop_back();
        self(self, x + 1);
        if (flag) return;
    };
    dfs(dfs, 1);
    if (!flag) cout << -1 << '\n';
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
