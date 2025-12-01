#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],b[200010],c[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(a[n]!=b[n])
    {
        cout<<"NO\n";
        return ;
    }
    c[n]=a[n]^b[n];
    for(int i=n-1;i>=1;i--) 
    {
        c[i]=a[i]^b[i];
        if(c[i])
        {
            if(c[i]==a[i+1]||c[i]==b[i+1]) continue;
            cout<<"NO\n";
            return ;
        }
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