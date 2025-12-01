#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    vector<int> a(2 * n + 1);
    vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= 2 * n; i++) {
        dp[i][i] = 1;
        if (i > n) a[i] = a[i - n];
    }

    for (int len = 2; len <= n; len++) 
    {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;
            if (a[l] == a[r]) dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            else dp[l][r] = max(dp[l + 1][r] + 1, dp[l][r - 1] + 1);
        }
    }

    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i][i + n - 1]);
    }
    cout << res << '\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}