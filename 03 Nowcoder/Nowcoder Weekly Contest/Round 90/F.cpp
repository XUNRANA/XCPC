#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
int ans[200010];
void dfs(int y)
{
    if(y<=0) return ;
    int x;
    for(int i=20;i>=0;i--) 
    if(y>>i&1)
    {
        x=1<<i;
        break;
    }
    int s=2*x-1;
    while(x<=y)
    {
        ans[x]=s-x;
        ans[s-x]=x;
        x++;
    }
    dfs(s-x);
}
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(n);
    for(int i=1;i<=n;i++) cout<<ans[a[i]]<<" \n"[i==n];
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