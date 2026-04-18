#include <bits/stdc++.h>
using namespace std;
int n;
vector<array<int,2>>g[100010];
int ans[100010];
void dfs(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v[0]==fa) continue;
        ans[v[0]]=min(ans[u],v[1]);
        dfs(v[0],fa);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int v,w;
        cin>>v>>w;
        g[v].push_back({i,w});
    }
    ans[0]=100;
    dfs(0,-1);
    int mx=0;
    for(int i=0;i<n;i++) if(g[i].size()==0) mx=max(mx,ans[i]);
    cout<<mx<<"\n";
    int f=0;
    for(int i=0;i<n;i++) if(g[i].size()==0&&ans[i]==mx) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
        // cout<<i<<" "<<ans[i]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}