#include <bits/stdc++.h>
using namespace std;
// #define int long long

int p[1000010];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt0 = 0, cnt1 = 0;
    for (char c: s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }
    if (cnt1 != cnt0) {
        cout << -1 << '\n';
        return;
    }
    
    vector<array<int, 2>> res;
    deque<pair<char,int>> st;
    
    s = " " + s;
    for(int i=1;i<=n;i++) p[i]=p[i-1]+(s[i]=='1');


    for (int i = 1; i <= n; i++) 
    {
        if(st.empty()) 
        {
            st.push_back({s[i],i});
            continue;
        }
        if (st.back().first == '0') 
        {
            if (s[i] == '1') 
            {
                res.push_back({st.back().second, i});
                st.pop_back();
            }
            else 
            {
                st.push_back({s[i],i});
            }
        } 
        else 
        {
            if (s[i] == '0') 
            {
                res.push_back({st.back().second, i});
                st.pop_back();
            } 
            else 
            {
                st.push_back({s[i],i});
            }
        }
    }

    sort(res.begin(),res.end());
    cout << res.size() << '\n';
    for (auto [x, y]: res) 
    {
        if(s[x]=='0')
        {
            int j=min(x,y);
            int xx=min(p[j],j-p[j])+1;
            cout<<xx<<" 1\n";
        }
        else
        {
            int j=min(x,y);
            int xx=min(p[j],j-p[j])+1;
            cout<<xx<<" 2\n";

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
