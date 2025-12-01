#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,s,a[110];
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(s<=a[1]) cout<<a[n]-s<<"\n";
    else if(s>=a[n]) cout<<s-a[1]<<"\n";
    else cout<<min(s-a[1],a[n]-s)+a[n]-a[1]<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}