#include <bits/stdc++.h>
using namespace std;
// #define int long long
void solve()
{
    int n = 5, cnt = 0;
    vector<vector<int>> query, key;
    vector<int> a;
    int e = 6;

    // cout << e << '\n';

    auto dfs1 = [&](auto&&self, int i) -> void {
        if (i > e) {
            query.push_back(a);
            return;
        }
        for (int j = 1; j <= n; j++) {
            a.push_back(j);
            self(self, i + 1);
            a.pop_back();
        }
    };

    auto dfs2 = [&](auto&&self, int i) -> void {
        if (i > e) {
            key.push_back(a);
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (a.empty() or j == a.back() + 1 or j == a.back() - 1) {
                a.push_back(j);
                self(self, i + 1);
                a.pop_back();
            }
        }
    };

    dfs1(dfs1, 1);
    dfs2(dfs2, 1);
    // cout << 1;

    auto check = [&](vector<int>&a, vector<int>&b) {
        for (int i = 0; i < e; i++) {
            if (a[i] == b[i]) return true;
        }
        return false;
    };

    // cout << query.size() << '\n';

    // for (auto k: key) {
    //     for (auto x: k) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';


    for (auto q: query) {
        bool flag = 1;
        // for (auto x: q) {
        //     cout << x << ' ';
        // }
        // cout << '\n';

        for (auto k: key) {
            if (!check(q, k)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (auto x: q) {
                cout << x << ' ';
            }

            cnt++;
            cout << '\n';
        }
    }
    cout << cnt << '\n';
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