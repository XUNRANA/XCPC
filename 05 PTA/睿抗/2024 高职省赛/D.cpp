#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    // cout<<s<<"\n";
    if(s.size()&1) s=s.substr(0,s.size()/2)+s.substr(s.size()/2+1);
    else s=s.substr(1,s.size()-2);
    // cout<<s<<"\n";
    for(int i=1;i<s.size();i+=2) cout<<s[i]<<s[i-1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

