#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[50010],b[50010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int t=-2e9;
    for(int i=1;i<=n;i++) 
    {
        if(b[i])
        {
            t=a[i]-b[i];
            break;
        }
    }
    if(t==-2e9) 
    {
        cout<<"YES\n";
        return ;
    }
    else if(t<0)
    {
        cout<<"NO\n";
        return ;
    }
    for(int i=1;i<=n;i++)
    if(max(a[i]-t,0ll)!=b[i])
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
    return 0;
}