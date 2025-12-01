#include<bits/stdc++.h>
using namespace std;
int T;
int n, m;
string s, t;
vector<int> bes[100010];
vector<string> ans;
int main(){
    cin >> T;
    while(T--) {
        ans.clear();
        for(int i = 0; i < 100000; i++) bes[i].clear();
        cin >> n >> m;
        cin >> s >> t;
        //n = s.size(); m = t.size();
        for(int i = 0; i <= m - n; i++) {
            int len = 0;
            for(int j = 0; j < n; j++) {
                if(s[j] != t[i+j]) len++;
                else break;
            }
            bes[len].push_back(i);
        }
        for(int i = 100000; i >= 0; i--) {
            if(bes[i].size() > 0) {
                for(auto p: bes[i]) {
                    string new_s;
                    for(int k = 0; k < n; k++) {
                        new_s.push_back(((s[k]-'0')^(t[p+k]-'0'))+'0');
                    }
                    ans.push_back(new_s);
                }
                break;
            }
        }
        sort(ans.begin(), ans.end());
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ans[ans.size()-1][i] == '1') cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}