#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    bool flag = 1;
    ll x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) flag = 0;
        x ^= a[i];
    }
    if (flag) {
        if (accumulate(a.begin(), a.end(), 0LL) & 1LL) cout << "Jiuhui" << '\n';
        else cout << "Akie" << '\n';
    } else {
        if (x == 0) cout << "Jiuhui" << '\n';
        else cout << "Akie" << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}