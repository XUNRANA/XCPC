#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,2>>g[200010];
int b[200010];
int dep[200010];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(auto v:g[u])
    {
        if(v[0]==fa) continue;
        b[v[0]]=v[1]-b[u];
        dfs(v[0],u);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
    b[1]=1;
    dfs(1,0);
    int mx1=-1e18,mi1=1e18;
    int mx2=-1e18,mi2=1e18;
    for(int i=1;i<=n;i++) 
    if(dep[i]&1) 
    {
        mx1=max(mx1,b[i]);
        mi1=min(mi1,b[i]);
    }
    else 
    {
        mx2=max(mx2,b[i]);
        mi2=min(mi2,b[i]);
    }


    if(mi1+mi2>=2) 
    {
        cout<<"YES\n";
        if(mi1<mi2)
        {
            int d=1-mi1;
            for(int i=1;i<=n;i++) 
            if(dep[i]&1) cout<<b[i]+d<<" ";
            else cout<<b[i]-d<<" ";
        }
        else
        {
            int d=1-mi2;
            for(int i=1;i<=n;i++) 
            if(dep[i]&1) cout<<b[i]-d<<" ";
            else cout<<b[i]+d<<" ";
        }
        cout<<"\n";
    }
    else cout<<"NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}