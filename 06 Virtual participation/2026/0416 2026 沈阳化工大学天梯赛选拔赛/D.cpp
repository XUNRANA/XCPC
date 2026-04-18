#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    while(n)
    {
        s=char('0'+n%2)+s;
        n/=2;
    }


    int add=0;
    if(s[s.size()-k]=='1') add=pow(2,k);
    
    // cout<<s<<"\n";
    s=s.substr(0,s.size()-k);
    // cout<<s<<"\n";
    while(k--) s+='0';
    // cout<<s<<"\n";

    reverse(s.begin(),s.end());
    int v=1;
    int ans=0;
    for(auto i:s)
    {
        ans+=(i-'0')*v;
        v*=2;
    }
    cout<<ans+add<<"\n";
    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}