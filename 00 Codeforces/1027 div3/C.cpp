#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[200010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) continue;
        else if(a[i]-a[i-1]==1) a[i]=a[i-1];
        else if(a[i]-a[i-1]>1) ans++;
    }
    cout<<ans<<"\n";
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