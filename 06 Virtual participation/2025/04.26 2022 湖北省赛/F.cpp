#include <bits/stdc++.h>
using namespace std;
// #define int long long
void solve() 
{
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << '\n' << 1;
    } else if (n == 2) {
        cout << 2 << '\n' << 1 << ' ' << 1;
    } else if (n == 3) {
        cout << 2 << '\n' << 2 << ' ' << 2;
    } else if (n == 4) {
        cout << 4 << '\n' << 2 << ' ' << 3 << ' ' << 3 << ' ' << 2;
    } else if (n == 5){
        cout << 6 << '\n' << 2 << ' ' << 3 << ' ' << 4 << ' ' << 2 << ' ' << 3 << ' ' << 4;
    } else {
        if (n & 1) {
            cout << (n - 2) * 2 << '\n';
            for (int i = 2; i < n; i++) cout << i << ' ';
            for (int i = 2; i < n; i++) cout << i << ' ';
        } else {
            cout << (n - 2) * 2 << '\n';
            for (int i = 2; i < n; i++) cout << i << ' ';
            for (int i = n - 1; i >= 2; i--) cout << i << ' ';
        }
    }
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