#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    string s;
    cin>>n>>s;
    int c1=0,c0=0;
    for(auto i:s) 
    if(i=='1') c1++;
    else c0++;

    int cnt1=0,cnt0=0;
    // 1 2 3 
    int ans=-1e18;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='1') cnt1++;
        else cnt0++;
        ans=max(ans,(cnt1-cnt0)*((c1-cnt1)-(c0-cnt0)));
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