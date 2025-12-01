#include <bits/stdc++.h>
using namespace std;

int x[2010], y[2010];

inline long long encode(int a, int b) {
    return ((long long)a << 32) ^ (unsigned)b;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    long long ans = 0;
    unordered_map<long long, int> mp, mp1;
    // mp.reserve(n * n);
    // mp1.reserve(n * n);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            long long dir = encode(dx, dy);
            long long mid = encode(x[i] + x[j], y[i] + y[j]);

            if(mp1.count(dir)) ans += mp1[dir]; // 平行边组合
            mp1[dir]++;

            if(mp.count(mid)) ans -= mp[mid]; // 去掉平行四边形
            mp[mid]++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
