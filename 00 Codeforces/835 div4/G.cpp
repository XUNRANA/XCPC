#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,u,v,w,f;
vector<pair<int,int>>g[100010];
set<int>st;
void dfs1(int u,int val,int fa)
{
    for(auto v1:g[u])
    {
        int v=v1.first;
        int w=v1.second;
        if(v==fa||v==b) continue;
        st.insert(val^w);
        dfs1(v,val^w,u);
    }
}
void dfs2(int u,int val,int fa)
{
    for(auto v1:g[u])
    {
        int v=v1.first;
        int w=v1.second;
        if(v==fa) continue;
        if(st.count(val^w)) f=1;
        dfs2(v,val^w,u);
    }
}
void solve()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++) 
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    f=0;
    st.clear();
    st.insert(0);
    dfs1(a,0,0);
    dfs2(b,0,0);
    if(f) cout<<"YES\n";
    else cout<<"NO\n";
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


