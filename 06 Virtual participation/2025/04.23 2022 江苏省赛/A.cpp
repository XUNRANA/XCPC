#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    map<string,vector<string>>mp;
    for(int i=1;i<=n;i++) 
    {
        string a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        if(mp[a].size()==5)
        {
            set<string>st;
            for(auto j:mp[a]) st.insert(j);
            if(st.size()==5)
            {
                cout<<"PENTA KILL!\n";
                return ;
            }
            else mp[a].erase(mp[a].begin());
        }
    }
    cout<<"SAD:(\n";
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