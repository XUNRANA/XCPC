#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long


void solve() 
{
    int n; cin >> n;
    array<ll, 32> cnt{};
    for (int i = 1;i <= n; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < 32; j++) {
            if ((x >> j) & 1) cnt[j]++;
        }
    }     
    
    auto check = [&]() -> bool {
        for (int i = 0; i <= 29; i++) {
            if (cnt[i] < cnt[i + 1]) return true;
        }
        return false;
    };

    while (check()) {
        for (int j = 0; j <= 29; j++) 
        {
            if (cnt[j + 1] > cnt[j]) {
                ll d = ceil(1.0 * (cnt[j + 1] - cnt[j]) / 3);
                cnt[j + 1] -= d;
                cnt[j] += d * 2;
            }
        }
    }

    cout << cnt[0] << '\n';
}


int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
