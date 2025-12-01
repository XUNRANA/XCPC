#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    string s;
    cin>>s;
    int ans=1;
    set<char>st;
    for(auto i:s)
    {
        if(st.count(i)) continue;
        else if(st.size()<3) st.insert(i);
        else
        {
            ans++;
            st.clear();
            st.insert(i);
        }
    }
    cout<<ans<<"\n";

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