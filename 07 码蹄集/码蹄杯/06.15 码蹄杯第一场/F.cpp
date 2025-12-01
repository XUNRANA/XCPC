#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s;
int a[200010];
int fa[200010];
vector<int>g[200010];
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
int dfs(int st)
{

}
void init()
{
}
void solve()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    if(!g[i].size())
    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}