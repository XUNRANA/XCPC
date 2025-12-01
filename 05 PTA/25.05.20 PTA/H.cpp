#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,q;
    cin>>n;
    set<pair<string,string>>st;
    while(n--)
    {
        string a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        st.insert({a,b});
    }
    cin>>q;
    while(q--)
    {
        string a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(st.count({a,b})) cout<<"(~_~)\n";
        else cout<<"o(@O@)o\n";
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