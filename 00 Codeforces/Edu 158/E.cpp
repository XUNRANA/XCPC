#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010

vector<int>g[N];
int dp[N];
int a[N];
int ans;
void dfs(int u,int fa)
{
    vector<int>son;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        son.push_back(dp[v]);
    }
    sort(son.begin(),son.end(),greater<int>());
    if(u==1)
    {
        dp[u]=a[u];
        int sum=0;
        for(int i=0;i<son.size();i++)
        {
            sum+=son[i];
            if(i==1) dp[u]=max(dp[u],sum);
            else dp[u]=max(dp[u],sum+a[u]);
            ans=max(ans,dp[u]);
        }
    }
    else
    {
        dp[u]=a[u];
        ans=max(ans,dp[u]);
        int sum=0;
        for(int i=0;i<son.size();i++)
        {
            sum+=son[i];
            if(i==0) dp[u]=max(dp[u],sum);
            else dp[u]=max(dp[u],sum+a[u]);
            
            
            if(i==1) ans=max(ans,sum);
            else ans=max(ans,a[u]+sum);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        g[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
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