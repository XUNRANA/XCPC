#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[200010];
int c[200010];
int ans[200010];
void solve()
{
    cin>>n;

    ans[0]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        c[a[i]]++;
        ans[i]=0;
    }
    int d=0;
    for(int i=0;i<=n;i++)
    {
        ans[c[i]]++;
        ans[n-i+1]--;
        d+=max(c[i]-1,0ll);
        if(!c[i]) break;
    }
    
    for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
    for(int i=0;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    
    for(int i=1;i<=n;i++) c[a[i]]--;
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}