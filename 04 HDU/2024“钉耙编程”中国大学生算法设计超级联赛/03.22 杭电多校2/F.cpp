#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
int a[100010];
pair<int,int> fx(int b,int a,int d,int c)
{
    int fz=b*c+a*d;
    int fm=a*c;
    int g=__gcd(fz,fm);
    return {fz/g,fm/g};
}
int x;
int y;
void dfs(int u,int fa,pair<int,int>p)
{
    if(x*p.second<p.first*y)
    {
        x=p.first;
        y=p.second;
    }
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u,fx(p.first,p.second,15,a[v]));
    }
}
void solve()
{
    int n,u,v;
    cin>>n;
    for(int i=0;i<=n;i++) g[i].clear();
    g[0].push_back(1);
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    x=0;
    y=1;
    dfs(0,-1,{x,y});
    cout<<x<<"/"<<y<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}