#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<array<int,3>>g[200010];
int s1[200010];
int s2[200010];
int d[200010];
int f[200010][20];
void dfs(int u,int fa)
{
    f[u][0]=fa;
    for(int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for(auto v:g[u])
    {
        if(v[0]==fa) continue;
        s1[v[0]]=s1[u]+v[1];
        s2[v[0]]=s2[u]+v[2];
        d[v[0]]=d[u]+1;
        dfs(v[0],u);
    }
}
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=2;i<=n;i++)
    {
        int p,a,b;
        cin>>p>>a>>b;
        g[p].push_back({i,a,b});
        g[i].push_back({p,a,b});
    }
    dfs(1,0);
    for(int i=2;i<=n;i++)
    {
        int u=i;
        int ss=s1[u];
        while(ss<s2[u])
        {
            int f1=0;
            for(int j=19;j>=0;j--)
            {
                if(ss<s2[f[u][j]])
                {
                    f1=1;
                    u=f[u][j];
                    break;
                }
            }
            if(!f1) u=f[u][0];
        }
        cout<<d[u]<<" ";
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