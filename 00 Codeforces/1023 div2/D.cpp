#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,vt[200010];
int dep[200010];
int f[200010];
vector<int>g[200010];
int mx;
void dfs(int u,int fa)
{
    f[u]=fa;
    dep[u]=dep[fa]+1;
    if(dep[u]>dep[mx])
    {
        mx=u;
    }
    else if(dep[u]==dep[mx])
    {
        mx=max(mx,u);
    }

    for(auto v:g[u])
    {
        if(v==fa||vt[v]) continue;
        dfs(v,u);
    }
}
void solve () 
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        g[i].clear();
        vt[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res=0;
    vector<array<int,3>>ans;
    while(res<n)
    {
        for(int i=1;i<=n;i++)
        {
            if(!vt[i])
            {
                mx=0;
                dfs(i,0);
                int a=mx;

                mx=0;
                dfs(a,0);
                int b=mx;

                ans.push_back({dep[b],max(a,b),min(a,b)});
                
                while(f[b]!=0)
                {
                    vt[b]=1;
                    res++;
                    b=f[b];
                }
                vt[b]=1;
                res++;
            }
        }
        
    }
    sort(ans.begin(),ans.end(),greater<array<int,3>>());
    for(auto i:ans) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" ";
    cout<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}