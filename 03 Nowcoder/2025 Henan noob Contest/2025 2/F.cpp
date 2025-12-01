#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P = 1000000007;
const int MAXP = 200005;  // 阶乘预处理上限（Lucas 局部用）

int fac[MAXP], inv[MAXP];
int r[40000010];
bool f[40000010];
vector<int> p;

// 快速幂
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

// 阶乘 & 逆元预处理（只到 MAXP）
void init_fac() {
    fac[0] = 1;
    for (int i = 1; i < MAXP; ++i) fac[i] = fac[i - 1] * i % P;
    inv[MAXP - 1] = ksm(fac[MAXP - 1], P - 2);
    for (int i = MAXP - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % P;
}

// 单次组合数计算（仅限 a, b < P）
int C_mod(int a, int b) {
    if (b > a || b < 0) return 0;
    return fac[a] * inv[b] % P * inv[a - b] % P;
}

// Lucas 组合数：支持任意 n, m
int lucas(int n, int m) {
    if (m == 0) return 1;
    return lucas(n / P, m / P) * C_mod(n % P, m % P) % P;
}

// 筛质数
void init_sieve(int n) {
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!f[i]) p.push_back(i);
        for (int j = 0; j < p.size() && i * p[j] <= n; ++j) {
            f[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;

    for (int i = n; i >= 1; i--) {
        int j = n / i;
        if (j >= m) {
            r[i] = lucas(j, m);
        }
    }

    // 质数容斥反演
    for (int i = p.size() - 1; i >= 0; i--) {
        int x = p[i];
        for (int j = n / x; j >= 1; j--) {
            r[j] = (r[j] - r[j * x] + P) % P;
        }
    }

    for (int i = 2; i <= n; i++) {
        ans = (ans + r[i]) % P;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();            // 初始化阶乘
    init_sieve(4e7);       // 筛到 4e7
    solve();
    return 0;
}
