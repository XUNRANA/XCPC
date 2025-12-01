#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long




void solve() 
{
    string s1, s2; cin >> s1 >> s2;
    ll X = stoll(s1), Y = stoll(s2);
    ll x = X / __gcd(X, Y), y = Y / __gcd(X, Y);

    // cout << x << ' ' << y << '\n';

    array<int, 2> res = {stoll(s1), stoll(s2)};
    map<string, set<int>> mp; 
    ll len = s1.length();

    // a , b

    for (int i = 1; i < (1 << len); i++) {
        ll a = 0, b = 0;
        string s = "0000000000";

        for (int k = 0; k < len; k++) {
            if ((i >> k) & 1) s[s1[k] - '0']++;
            else b = b * 10 + s1[k] - '0';
        }
        if (b == 0) continue;
        mp[s].insert(b);
    }

    len = s2.length();

    for (int i = 1; i < (1 << len); i++) {
        ll a = 0, b = 0;
        string s = "0000000000";

        for (int k = 0; k < len; k++) {
            if ((i >> k) & 1) s[s2[k] - '0']++;
            else b = b * 10 + s2[k] - '0';
        }

        if (b * x % y or b == 0) continue;
        auto aim = b * x / y;
        // cout << aim << ' ' << b << '\n';
        if (mp[s].count(aim)) res = min(res, {aim, b});
    }
    cout << res[0] << ' ' << res[1] << '\n';
}


int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
