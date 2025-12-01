#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,2>>ans;
vector<int>g[200010];
int id;
void dfs(int u,int fa,int f)
{
    if(u==id) f^=1;    
    for(auto v:g[u])
    {
        if(v==fa) continue;
        if(f) ans.push_back({v,u});
        else ans.push_back({u,v});
        dfs(v,u,f^1);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    ans.clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    id=-1;
    for(int i=1;i<=n;i++) 
    if(g[i].size()==2)
    {
        id=i;
        break;
    }

    if(id==-1) cout<<"NO\n";
    else
    {
        if(id==1) dfs(2,0,0);
        else dfs(1,0,0);
        cout<<"YES\n";
        for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
    }
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