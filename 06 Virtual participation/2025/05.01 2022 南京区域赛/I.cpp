#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    string s; cin >> s;
    int n = s.size();
    map<char, int> cnt;
    int mx = 0;

    for (auto c: s) {
        cnt[c]++;
        mx = max(mx, cnt[c]);
    }
    cout << n - mx << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}