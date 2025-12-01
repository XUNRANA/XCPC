#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
#define N 500010
int ans[N];
vector<int>g[N];
int f[N][20];
int fk[N];
int a[N];
int k;
int dp[N][32][2];
int lowbit(int x)
{
    return x&-x;
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    
    for(int i=0;i<32;i++) dp[u][i][0]=dp[u][i][1]=0;

    for(int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}

void dfs1(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs1(v,u);
        for(int i=0;i<32;i++) 
        {
            dp[u][i][0]+=dp[v][i][0];
            dp[u][i][1]+=dp[v][i][1];
        }
    }
    // 01
    // 11
    for(int i=0;i<32;i++) 
    if(a[u]>>i&1) dp[u][i][1]++;
    else dp[u][i][0]++; 

    for(int i=0;i<32;i++) 
    if(a[u]>>i&1) dp[fk[u]][i][1]--;
    else dp[fk[u]][i][0]--; 

    
    ans[u]=0;
    for(int i=0;i<32;i++) ans[u]=(ans[u]+(1ll<<i)*dp[u][i][0]%P*dp[u][i][1]%P)%P;
    // cout<<u<<" "<<ans[u]<<"\n";
}

void solve()
{
    int n,q;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) 
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) 
    {
        int t=k+1;
        int fa=i;
        while(t)
        {
            int x=lowbit(t);
            fa=f[fa][__lg(x)];
            t-=x;
        }
        fk[i]=fa;
        // cout<<i<<" "<<fa<<"\n";
    }
    dfs1(1,0);

    while(q--)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<"\n";
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