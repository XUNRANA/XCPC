#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[200010];
int a[200010];
int f[200010];
int d[200010];
int ans;
void dfs(int u,int fa)
{
    f[u]=fa;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void add(int p)
{
    int d1=0;
    // cout<<p<<"!\n";
    while(p&&d1<ans)
    {
        ans=min(ans,d[p]+d1);
        d[p]=min(d[p],d1);
        // cout<<p<<" "<<d1<<"??\n";
        p=f[p];
        d1++;
    }
}
void solve()
{
    int n,s;
    cin>>n>>s;
    
    for(int i=1;i<=n;i++) 
    {
        g[i].clear();
        d[i]=1e9;
    }

    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=n+1;
    dfs(1,0);
    add(s);
    

    for(int i=1;i<n;i++) 
    {
        add(a[i]);
        cout<<ans<<" ";
    }
    cout<<"\n";
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