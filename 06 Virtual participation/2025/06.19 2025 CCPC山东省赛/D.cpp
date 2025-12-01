#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
            cin >> n;
            unordered_map<int, unordered_map<int,int>>mp;
            unordered_map<int, unordered_map<int,vector<int>>>mp2;
        for(int i= 1;i <= n; i++){
            int a, b;
            cin >> a >> b;
            // cout << a << " " << b << endl;
            mp[a][b]++;
            mp2[a][b].push_back(i);
        }
        vector<int>tt;
        for(auto [x, y] : mp){
            tt.push_back(x);
        }
        sort(tt.rbegin(), tt.rend());
        int m = tt.size();
        vector<vector<pair<int, int>>>g(m);
        int id = 0;
        // cout << m << endl;
        for(auto x : tt){
            for(auto [a, b] : mp[x]){
                g[id].push_back({a, b});
                // cout << a <<" " << b << endl;
            }
            sort(g[id].begin(), g[id].end(),greater<pair<int,int>>());
            id++;
        }
        int ans = 0;
         vector<int>p;
        for(int i = 0;i < m;i ++)
        {
            int sum = ans, a1 = 0;
            int d = -1, cnt = 0;
            for(int j = 0;j < g[i].size();j ++)
            {
                int x = g[i][j].first;
                int y = g[i][j].second;
                a1 += y;
                if(sum < min(x, ans) + a1){
                    sum = min(x, ans) + a1;
                    d = j;
                }
            }
            ans = sum;
           
            if(d == -1)continue;
            else{
                int aa = tt[i];
                for(int j = 0; j <= d;j ++){
                    for(auto x : mp2[aa][g[i][j].first]){
                        p.push_back(x);
                    }
                }
            }
        }
        cout << ans << "\n";
        for(int i= 0, j = p.size() -1;i < ans; i++)cout << p[j -i] << " ";
        cout << "\n";
    }

    return 0 ;
}