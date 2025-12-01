#include <bits/stdc++.h>
using namespace std;

#define N 1010
int vt[N];
int blk[N];
vector<int>g[N];
void dfs(int u)
{
    vt[u]=1;
    for(auto v:g[u])
    {
        if(vt[v]||blk[v]) continue;
        dfs(v);
    }
}
void solve()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++) g[i].clear(),vt[i]=blk[i]=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    

    vector<int>ans;
    
    while(x!=y) 
    {
        ans.push_back(x);
        for(int i=1;i<=n;i++) vt[i]=0;
        blk[x]=1;
        dfs(y);
        for(auto v:g[x])
        {
            if(vt[v])
            {
                x=v;
                break;
            }
        }
    }
    ans.push_back(y);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

