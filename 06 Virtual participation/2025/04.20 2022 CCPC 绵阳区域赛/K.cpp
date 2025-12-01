#include <iostream>
#include <vector>
using ll = long long;
// using namespace std;

inline void read(char &c) {
    c = getchar();
    while (c > 'z' or c < 'a') c = getchar();
}

const ll mod1 = 1610612741, mod2 = 1e9 + 7, p1 = 13331, p2 = 131;
const int N = 7e6 + 1;

std::vector<std::vector<bool>> vis(5, std::vector<bool>(N));

void reset(int x, int idx) {
    for (int i = 0; i < 5; i++) {
        if ((x >> i) & 1) vis[i][idx] = 1;
    }
}

inline int get(int idx) {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        if (vis[i][idx]) res |= (1 << i);
    }
    return res;
}

void solve() {
    ll P1 = 1, P2 = 1;
    ll k1 = 0, k2 = 0;
    int n, m; 
    scanf("%d %d", &n, &m);
    char c;
    for (int i = 1; i <= n; i++) {
        read(c);
        c -= 'a';
        // cout << char(c + 'a') << " ";
        k1 = (k1 * p1 + c) % mod1;
        k2 = (k2 * p2 + c) % mod2;
        P1 = P1 * p1 % mod1;
        P2 = P2 * p2 % mod2;
    }

    ll h1 = 0, h2 = 0, m1 = 0, m2 = 0;
    for (int i = 1; i <= n; i++) {
        read(c);
        c -= 'a';
        // cout << char(c + 'a') << ' ';
        h1 = (h1 * p1 + c) % mod1;
        h2 = (h2 * p2 + c) % mod2;
        reset(c, i);
    }
    int res = 0;
    if (h1 == k1 and h2 == k2) res++;
    // printf("%d\n", res);

    for (int i = 1; i <= m - n; i++) {
        read(c);
        c -= 'a';
        h1 = (h1 * p1 + c) % mod1;
        h2 = (h2 * p2 + c) % mod2;
        reset(c, i + n);
        int x = get(i);
        // cout << char(x + 'a') << ' ';
        // cout << x << ' ';
        m1 = (m1 * p1 + x) % mod1;
        m2 = (m2 * p2 + x) % mod2;
        // cout << (h1 - m1 * P1 + mod1) % mod1 << ' ' << k1 << ' ' << (h2 - m2 * P2 + mod2) % mod2 << ' ' << k2 <<   
        if ((h1 - m1 * P1 % mod1 + mod1) % mod1 == k1 and (h2 - m2 * P2 % mod2 + mod2) % mod2 == k2) res++;
    }
    printf("%d\n", res);
}

int32_t main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}