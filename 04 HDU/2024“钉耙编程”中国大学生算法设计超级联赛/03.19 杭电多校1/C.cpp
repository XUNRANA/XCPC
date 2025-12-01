#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define N 1000010
vector<int>g[N];
int a[N],n;
int t[N],ts[N],tss[N];
int sz[N],big[N],L[N],R[N],Node[N],totdfn;
int ans[N];//u的重儿子为w[u]
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x,int t[])
{
    while(i<=1e6)
    {
        t[i]+=x;
        i+=lowbit(i);
    }
}
int g_sum(int l,int r,int t[])
{
    int s=0;
    while(r)
    {
        s+=t[r];
        r-=lowbit(r);
    }
    l--;
    while(l)
    {
        s-=t[l];
        l-=lowbit(l);
    }
    return s;
}

void dfs0(int u,int fa)
{
    L[u]=++totdfn;
    Node[totdfn]=u;
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs0(v,u);
        sz[u]+=sz[v];
        if(!big[u]||sz[v]>sz[big[u]]) big[u]=v; 
    }
    R[u]=totdfn;
}
int fans;
int get(int x)
{
    int res=0;
    res+=x*(x*g_sum(1,x,t)-g_sum(1,x,ts)); 
    res+=g_sum(x,1e6,tss)-g_sum(x,1e6,ts)*x;
    return res; 
}
void add(int u)
{
    add(a[u],1,t);
    add(a[u],a[u],ts);
    add(a[u],a[u]*a[u],tss);
    fans+=get(a[u]);
}
void del(int u)
{
    add(a[u],-1,t);
    add(a[u],-a[u],ts);
    add(a[u],-a[u]*a[u],tss);
    fans-=get(a[u]);
}
void dfs(int u,int fa,bool keep)
{
    for(auto v:g[u]) if(v!=fa&&v!=big[u]) dfs(v,u,0);//遍历轻儿子，不计算影响
    if(big[u]) dfs(big[u],u,1);//遍历重儿子，计算影响
    for(auto v:g[u])    //添加轻儿子的影响
    {
        if(v!=fa&&v!=big[u]) 
        for(int i=L[v];i<=R[v];i++) add(Node[i]);
    }
    add(u);
    // cout<<u<<"\n";
    ans[u]=fans;//计算答案
    if(!keep) for(int i=L[u];i<=R[u];i++) del(Node[i]);//如果不保留、需要删除
}

void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs0(1,0);
    dfs(1,0,0);
    int res=0;
    for(int i=1;i<=n;i++) res^=2*ans[i];
    cout<<res<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}