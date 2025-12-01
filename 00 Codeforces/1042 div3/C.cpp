#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],b[200010];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]%=k,a[i]=min(a[i],k-a[i]);
    for(int i=1;i<=n;i++) cin>>b[i],b[i]%=k,b[i]=min(b[i],k-b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    if(a[i]!=b[i])
    {
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}