#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    string ns="";
    ns+=s[0];
    for(int i=1;i<n;i++) if(s[i]==s[i-1]) ans++;
    else ns+=s[i];

    if(ns[0]=='0')//010
    {
        if(ns.size()>=3) swap(ns[1],ns[2]);
    }
    else//101
    {
        if(ns.size()>=2) swap(ns[0],ns[1]);
    }

    if(ns[0]=='1') ans++;
    ans++; 
    for(int i=1;i<ns.size();i++)
    {
        if(ns[i]!=ns[i-1]) ans+=2;
        else ans++;
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