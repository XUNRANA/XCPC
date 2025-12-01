#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n==1) cout<<a[1];
    else if(n==2) cout<<a[2]-a[1];
    else
    {
        
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}