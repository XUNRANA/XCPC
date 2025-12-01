#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int n,m;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    if(n==m&&a[n]==b[m-1]) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}