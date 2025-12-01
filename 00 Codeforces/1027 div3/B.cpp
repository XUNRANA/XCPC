#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve () 
{
    int n,k;
    cin>>n>>k;
    k=n/2-k;
    string s;
    cin>>s;
    int c0=0,c1=0;
    for(auto i:s) 
    if(i=='0') c0++;
    else c1++;



    if(c0>=k&&c1>=k)
    {
        c0-=k;
        c1-=k;
        if(c0&1||c1&1) cout<<"NO\n";
        else cout<<"YES\n";
    }
    else cout<<"NO\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}