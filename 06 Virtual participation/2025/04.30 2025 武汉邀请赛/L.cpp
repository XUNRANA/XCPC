#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[3010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int res = 1;

    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            int mid = a[l] + a[r];
            if (mid & 1) continue;
            mid >>= 1;
            auto L = lower_bound(a + 1, a + 1 + n, mid) - a;
            auto R = upper_bound(a + 1, a + 1 + n, mid) - a;
            R -= 1;
            if (L > R) continue;

            int len = r - l + 1;
            int m = l + (r - l) / 2;
            if (L <= m and m <= R) res = max(res, len);
            else {
                int res1 = 0, res2 = 0;
                int cnt1 = L - l, cnt2 = r - L;
                if (cnt2 >= cnt1 + 1) res1 = cnt1 * 2 + 2;
                else res1 = cnt2 * 2 + 1;

                cnt1 = R - l, cnt2 = r - R;
                if (cnt2 >= cnt1 + 1) res2 = cnt1 * 2 + 2;
                else res2 = cnt2 * 2 + 1;

                res = max({res, res1, res2});
            }
        }
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
