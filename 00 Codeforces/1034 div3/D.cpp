#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,k,cnt;
    string s;
    cin>>n>>k>>s;
    cnt=count(s.begin(),s.end(),'1');
    if(k>=cnt||n<2*k) cout<<"Alice\n";
    else cout<<"Bob\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}