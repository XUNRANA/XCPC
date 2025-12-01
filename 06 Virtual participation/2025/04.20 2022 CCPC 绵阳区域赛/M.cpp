#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool beat(char a,char b)
{
    if(a=='S') return b=='P';
    if(a=='P') return b=='R';
    if(a=='R') return b=='S';
}
void solve() 
{
    string s;
    cin>>s;
    stack<char>st;
    for(auto i:s)
    {
        while(!st.empty()&&!beat(st.top(),i)) st.pop();
        st.push(i);
    }
    char ans;
    while(!st.empty()) 
    {
        ans=st.top();
        st.pop();
    }
    cout<<ans<<"\n";
}

int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}