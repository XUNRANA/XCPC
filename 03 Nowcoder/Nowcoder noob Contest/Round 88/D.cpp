#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, m;
    cin >> n >> m;
    vector dp(m + 1, vector(n, false));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) 
    {
        int x;
        cin >> x;
        x %= n;
        for (int j = 0; j < n; j++)
            dp[i][j] = dp[i - 1][(j + x) % n] | dp[i - 1][(j - x + n) % n];
    }
    cout << (dp[m][0] ? "YES" : "NO") << "\n";
}