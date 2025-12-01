#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,s,a[110];
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    if(a[i]-a[i-1]>s)
    {
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
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