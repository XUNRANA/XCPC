#include<bits/stdc++.h>
using namespace std;
int n, m, x;
long long s[110][110];
long long a[110][110];
long long sum_s[110][110];
long long sum_a[110][110];
long long dp[110][10010];
int main() {
    int T;
    cin >> T;
    while(T--) {
        memset(dp, 0, sizeof(dp));
        memset(sum_s, 0, sizeof(sum_s));
        memset(sum_a, 0, sizeof(sum_a));
        cin >> n >> m >> x;
        long long tot = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> s[i][j] >> a[i][j];
                sum_s[i][j] = sum_s[i][j-1] + s[i][j];
                sum_a[i][j] = sum_a[i][j-1] + a[i][j];
                tot += a[i][j];
            }
        }
        long long max_ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= x; k++) {
                    if(i) dp[i][k] = max(dp[i][k], dp[i-1][k]);
                    if(k >= sum_s[i][j]) {
                        if(i) {
                            dp[i][k] = max(dp[i][k], dp[i-1][k-sum_s[i][j]] + sum_a[i][j]);
                        }
                        else {
                            dp[i][k] = max(dp[i][k], sum_a[i][j]);
                        }
                    } 
                    max_ans = max(max_ans, dp[i][k]);
                }
            }
        }
        cout << tot - max_ans << "\n";
    }

    return 0;
}