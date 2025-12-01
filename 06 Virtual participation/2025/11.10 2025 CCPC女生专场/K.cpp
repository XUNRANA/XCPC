#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
vector<int>g[100010];
int jc[100010];
int sz[100010];
int sz1[100010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=1e5;i++) jc[i]=jc[i-1]*i%P;
}
bool cmp(int x,int y)
{
    return sz[x]<sz[y];
}
int ans=1;
void dfs(int u)
{
    sz[u]=1;
    map<int,int>mp;
    for(auto v:g[u])
    {
        dfs(v);
        sz[u]+=sz[v];
        mp[sz[v]]++;
    }
    for(auto v:mp) ans=ans*jc[v.second]%P;
}
int ans1=0;
void dfs1(int u)
{
    sort(g[u].begin(),g[u].end(),cmp);
    for(int i=0;i<g[u].size();i++)
    {
        if(i==g[u].size()-1)
        {
            dfs1(g[u][i]);
            sz1[u]+=sz1[g[u][i]];
        }
        else
        {
            dfs1(g[u][i]);
            sz1[g[u][i+1]]+=sz1[g[u][i]];
        }   
    }
    ans1=ans1+sz1[u];
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) sz1[i]=1;
    for(int i=2;i<=n;i++) 
    {
        int f;
        cin>>f;
        g[f].push_back(i);
    }
    dfs(1);
    dfs1(1);
    cout<<ans1<<"\n"<<ans<<"\n";
}
signed main() 
{ 
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
