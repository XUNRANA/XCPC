#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;
    if(s.substr(s.size()-12,12)=="isallyouneed")
    {
        cout<<"Yes\n";
        cout<<s.substr(0,s.size()-12)<<"\n";
    }
    else cout<<"No\n";
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
