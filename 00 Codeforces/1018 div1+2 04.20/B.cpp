#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
void solve() 
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ans+=x;
        a[i]=min(a[i],x);
    }
    sort(a+1,a+1+n);
    k=n+1-k;
    for(int i=1;i<=k;i++) ans-=a[i];
    cout<<ans+1<<"\n";
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