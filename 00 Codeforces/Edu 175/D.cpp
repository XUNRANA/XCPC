#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
vector<int>g[300010];
int dep[300010];
int sz[300010];
int ans[300010];
int fa[300010];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}

void solve()
{
    int n,f;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),sz[i]=ans[i]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>f;
        fa[i]=f;
        g[i].push_back(f);
        g[f].push_back(i);
    } 
    dfs(1,0);
    ans[1]=1;
    queue<int>q;
    for(auto v:g[1]) 
    {
        q.push(v);
        ans[v]=1;
        sz[dep[v]]+=ans[v];
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // cout<<u<<"!\n";
        for(auto v:g[u])
        {
            if(v==fa[u]) continue;
            // cout<<v<<"??\n";
            ans[v]+=(sz[dep[u]]-ans[u]+P)%P;
            ans[v]%=P;
            // if(v==6) cout<<ans[v]<<"??\n";
            sz[dep[v]]+=ans[v];
            sz[dep[v]]%=P;
            q.push(v);
        }
    }
    // for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    // cout<<"\n";
    int res=0;
    for(int i=1;i<=n;i++) res=(res+ans[i])%P;
    cout<<res<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

