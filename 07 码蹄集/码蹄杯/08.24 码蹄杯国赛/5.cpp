#include <bits/stdc++.h>
using namespace std;

int n,a[30010];
vector<int>g[30010];
map<int,int>st[30010];

int ans[30010];
void dfs(int u,int fa)
{
    if(a[u]) st[u][0]++;
    
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        for(auto v1:st[v]) 
        {
            st[u][v1.first+1]++;
        }
    }
}


void dfs1(int u,int fa)
{
    ans[u]=st[u].size();


    for(auto v:g[u])
    {
        if(v==fa) continue;


        for(auto v1:st[v]) 
        {
            st[u][v1.first+1]--;
            if(!st[u][v1.first+1]) st[u].erase(v1.first+1);
        }

        for(auto v1:st[u])
        {
            st[v][v1.first+1]++;
        }



        dfs1(v,u);


        for(auto v1:st[u]) 
        {
            st[v][v1.first+1]--;
            if(!st[v][v1.first+1]) st[v].erase(v1.first+1);
        }

        for(auto v1:st[v])
        {
            st[u][v1.first+1]++;
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) 
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);

    dfs1(1,0);

    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
