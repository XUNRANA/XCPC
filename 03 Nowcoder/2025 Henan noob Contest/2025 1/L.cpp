#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[1]=0;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}