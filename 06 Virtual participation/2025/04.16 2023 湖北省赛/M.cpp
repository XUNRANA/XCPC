#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6;

void solve() 
{
    int x, y; cin >> x >> y;
    for (int b = 0; b <= x&&1000*b<=y; b++) 
    {
        int t=y-1000*b;
        if(t%2500==0)
        {
            int cc=t/2500;
            if(cc+b<=x)
            {
                cout<<x-cc-b<<" "<<b<<" "<<cc<<"\n";
                return ;
            }
        }
    }
    cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}