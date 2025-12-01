int sz[N],big[N],L[N],R[N],Node[N],totdfn;
//u的重儿子为big[u]
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