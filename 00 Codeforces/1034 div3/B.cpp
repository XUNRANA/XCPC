#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
void solve()
{
    int n,j,k;
    cin>>n>>j>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int val=a[j];
    sort(a+1,a+1+n);
    if(val!=a[n]&&k==1) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}