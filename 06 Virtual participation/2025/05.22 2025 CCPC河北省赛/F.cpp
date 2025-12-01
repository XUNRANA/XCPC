#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[1000010];
int a[1000010];
int ff[1000010][30];
int dep[1000010];
void dfs(int u,int fa)
{
    if(a[u]+1==a[fa])
    {
        ff[u][0]=fa;
        for(int j=1;j<=20;j++) ff[u][j]=ff[ff[u][j-1]][j-1];
    }
    dep[u]=dep[fa]+1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) 
    {
        int f;
        cin>>f;
        g[f].push_back(i);
        g[i].push_back(f);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        int ss=s;
        while(1)
        {
            int flag=0;
            for(int i=20;i>=0;i--)
            if(ff[s][i]!=0) 
            {
                s=ff[s][i];
                flag=1;
                break;
            }
            if(!flag) break;
        }
        if(dep[t]<dep[s]) cout<<a[s]-a[ss]+1<<"\n";
        else cout<<max(a[t]-a[ss]+1,0ll)<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
