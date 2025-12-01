#include<bits/stdc++.h>
using namespace std;
int T;
int n, m, k;
int col[2050];
int dt[3050][3050];
int main(){
    cin >> T;
    while(T--) {
        memset(col, 0, sizeof(col));
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> dt[i][j];
            }
        }
        int l = -1, r=m;
        int app = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(col[dt[i][j]] == 0) {
                    app++;
                }
                col[dt[i][j]]++;
            }
            if(app == k) {
                l = i;
                break;
            }
        }
        if(l == -1) {
            cout << 0 << "\n";
            continue;
        }
        for(;l < n; l++) {
            while(app == k && r >= 0) {
                for(int j = 0; j <= l; j++) {
                    col[dt[j][r]]--;
                    if(col[dt[j][r]] == 0) app--;
                }
                r--;
            }
            ans += m-r-1;
            for(int j = 0; j <= r; j++) {
                if(col[dt[l+1][j]] == 0) app++;
                col[dt[l+1][j]] ++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}