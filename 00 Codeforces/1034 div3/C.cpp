#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[200010];
int p[200010];
int s[200010];
int ans[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    p[0]=1e6;
    for(int i=1;i<=n;i++) p[i]=min(p[i-1],a[i]);
    
    s[n+1]=0;
    for(int i=n;i>=1;i--) s[i]=max(s[i+1],a[i]);

    for(int i=1;i<=n;i++)
    {
        if(p[i]==a[i]||s[i]==a[i]) ans[i]=1;
        else ans[i]=0;
    }

    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}