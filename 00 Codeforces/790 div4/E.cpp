#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[200010];
void solve() 
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    for(int i=2;i<=n;i++) a[i]+=a[i-1];
    while(q--)
    {
        int x;
        cin>>x;
        if(a[n]<x) cout<<"-1\n";
        else cout<<lower_bound(a+1,a+1+n,x)-a<<"\n";
    }
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