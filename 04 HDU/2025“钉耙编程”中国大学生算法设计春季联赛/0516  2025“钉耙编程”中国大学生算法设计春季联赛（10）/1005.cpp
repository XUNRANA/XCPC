#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,a[100010];
void solve() 
{
    cin>>t>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int s=0;
    for(int i=1;i<=m;i++) s+=a[i];
    if(s>t) cout<<"-1\n";
    else cout<<(t-s)/40<<"\n";
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