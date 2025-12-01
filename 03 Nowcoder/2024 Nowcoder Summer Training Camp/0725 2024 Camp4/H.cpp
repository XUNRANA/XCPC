#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, a[100010];

void solve() {
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    if (s.size() == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<int> b(s.begin(), s.end());
    int g = 0;
    for (int i = 1; i < b.size(); i++) {
        g = gcd(g, b[i] - b[i-1]);
    }

    cout << g << "\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
