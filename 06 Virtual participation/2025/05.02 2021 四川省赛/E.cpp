#include <bits/stdc++.h>
using namespace std;
int n,m;
int vt[100010];
vector<int>g[100010];
int ans,idx;
void dfs(int u)
{
    vt[u]=1;
    if(u==n) return ;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vt[v]) continue;
        if(v!=idx+1)
        {
            ans++;
            i--;
        }
        idx++;
        dfs(idx);
    }
    while(u==1&&idx!=n) 
    {
        ans++;
        idx++;
        dfs(idx);
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) g[i].clear(),vt[i]=0;
    set<pair<int,int>>st;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        if(u!=v) st.insert({u,v});
    }
    for(auto i:st) g[i.first].push_back(i.second);
    idx=1;
    ans=0;
    dfs(1);
    cout<<ans<<"\n";
}


int32_t main() 
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}