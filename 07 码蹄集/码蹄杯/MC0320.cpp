#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int ans=n;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1]) ans+=i;
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
}