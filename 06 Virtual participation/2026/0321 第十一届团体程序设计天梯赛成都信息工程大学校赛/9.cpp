#include <bits/stdc++.h>
using namespace std;


map<array<int,2>,int>mp;
set<int>g[100010];
int vt[100010];
vector<int>ans;
void dfs(int u,int f)
{
    ans.push_back(u);
    vt[u]=1;
    for(auto v:g[u])
    {
        if(v==f||vt[v]) continue;
        dfs(v,u);
    }
}
void solve()
{
    int n;
    cin>>n;
    int rr=0;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u==v) rr=i;
        if(u>v) swap(u,v);
        g[u].insert(v);
        g[v].insert(u);
        if(mp.count({u,v})) rr=i;
        mp[{u,v}]=i;
    }
    if(rr) 
    {
        cout<<rr<<"\n";
        return ;
    }

    queue<int>q;
    for(int i=1;i<=n;i++) if(g[i].size()==1) q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            g[v].erase(u);
            if(g[v].size()==1) q.push(v);
        }
        g[u].clear();
    }
    int st=0;
    for(int i=1;i<=n;i++) if(g[i].size()==2) st=i;
    
    dfs(st,0);
    
    if(ans.size()==1)
    {
        cout<<mp[{ans[0],ans[0]}]<<"\n";
        return ;
    }
    // for(auto i:ans) cout<<i<<"\n";
    int res=mp[{min(ans[0],ans.back()),max(ans[0],ans.back())}];
    for(int i=1;i<ans.size();i++)
    {
        res=max(res,mp[{min(ans[i],ans[i-1]),max(ans[i],ans[i-1])}]);
    }
    cout<<res<<"\n";
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}