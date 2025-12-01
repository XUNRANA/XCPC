#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[1000010];
int sz[1000010];
int ans;
void dfs(int u,int fa)
{
    sz[u]=1;
    vector<int>a;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);

        if(!sz[v]) continue;
        a.push_back(sz[v]);
        sz[u]+=sz[v];
    }

    if(sz[u]==m)
    {
        sz[u]=0;
        ans++;
    }
    else if(sz[u]>m)
    {
        sort(a.begin(),a.end());
        int res=1;
        for(int i=0;i<a.size();i++)
        {
            res+=a[i];
            if(res==m)
            {
                // 0 1 2 3 4 
                ans+=a.size()-i;
                sz[u]=0;
                break;
            }
            else if(res>m)
            {
                ans+=a.size()-i;
                sz[u]=res-a[i];
                break;
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(m==1) cout<<n<<"\n";
    else 
    {
        dfs(1,0);
        if(sz[1]) ans++;
        cout<<ans<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}