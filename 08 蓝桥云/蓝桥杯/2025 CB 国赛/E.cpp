#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s,t;
    int n,m;
    cin>>n>>m;
    cin>>s>>t;
    sort(t.begin(),t.end());
    int i=0,j=0;
    string ans="";
    while(i<s.size()&&j<t.size())
    {
        if(s[i]<=t[j]) ans+=s[i++];
        else ans+=t[j++];
    }
    while(i<s.size()) ans+=s[i++];
    while(j<t.size()) ans+=t[j++];
    cout<<ans<<"\n";
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