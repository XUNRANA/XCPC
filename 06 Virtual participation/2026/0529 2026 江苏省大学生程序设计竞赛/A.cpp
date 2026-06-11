#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int A[N], B[N];
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i= 1;i <= n;i++){
        int a, b;
        cin >> A[i] >> B[i];
    }
    int l = 0, r = 3e12;
    auto check = [&](int mid){
        vector<array<int,2>>p;
        for(int i= 1;i <= n;i++){
            if(A[i] <= mid){
                int l = B[i] - (mid - A[i]);
                int r = B[i] + (mid - A[i]);
                p.push_back({l, r});
            }
        }
        sort(p.begin(), p.end());
        if(p.size() == 0)return false;
        if(p[0][0] > 0)return false;
        int vis = p[0][1];
        for(int i = 1;i < p.size();i++){
            if(p[i][0]<= vis + 1) vis = max(vis, p[i][1]);
            else return false;
        }
        return vis >= k;
    };
    while(r > l){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << l << "\n";

}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}