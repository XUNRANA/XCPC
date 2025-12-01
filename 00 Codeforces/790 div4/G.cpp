#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
string s;
vector<int>g[4010];
int dp[4010][2];
void dfs(int u,int fa)
{
    dp[u][1]=(s[u]=='W');
    dp[u][0]=(s[u]=='B');
    for(auto v:g[u]) 
    {
        if(v==fa) continue;
        dfs(v,u);
        dp[u][1]+=dp[v][1];
        dp[u][0]+=dp[v][0];
    }
    if(dp[u][1]==dp[u][0]) ans++;
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        g[i].push_back(f);
        g[f].push_back(i);
    }
    cin>>s;
    s=" "+s;
    ans=0;
    dfs(1,0);
    cout<<ans<<"\n";
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