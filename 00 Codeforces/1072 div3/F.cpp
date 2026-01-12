#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[200010];
int dp[200010];
void dfs(int u,int fa)
{
    bool is_leaf=1;
    int cur=1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        is_leaf=0;
        dfs(v,u);
        int nxt=0;
        for(int i=0;i<3;i++)
            if((cur>>i)&1)
                for(int j=0;j<3;j++)
                    if((dp[v]>>j)&1)
                        nxt|=(1<<((i+j)%3));
        cur=nxt;
    }
    if(is_leaf) dp[u]=2; 
    else dp[u]=cur|2;   
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    if(dp[1]&1) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}