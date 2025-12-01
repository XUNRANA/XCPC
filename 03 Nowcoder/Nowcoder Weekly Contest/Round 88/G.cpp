#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int mx[200010];
int a[200010];
int fa[200010];
vector<int>yz[200010];
void dfs(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        mx[v]=mx[u]+a[v];
        dfs(v,u);
    }
}
void fx(int u)
{
    int y=u;//叶子
    yz[y].push_back(y);
    while(fa[u]!=1)
    {
        u=fa[u];
        yz[u].push_back(y);
    }
    yz[fa[u]].push_back(y);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) yz[i].clear(),g[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        fa[i]=f;
        g[i].push_back(f);
        g[f].push_back(i);
    }
    mx[1]=a[1];
    dfs(1,0);
    multiset<int>st;
    for(int i=2;i<=n;i++)
    {
        if(g[i].size()==1) 
        {
            fx(i);
            st.insert(mx[i]);
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int len=0;
        for(auto v:yz[x])
        {
            len=max(len,mx[v]-mx[x]+a[x]);
            st.erase(st.find(mx[v]));
        }
        int ans=max(len+mx[y],mx[fa[x]]);
        if(st.size()) ans=max(ans,*st.rbegin());
        
        cout<<ans<<"\n";
        for(auto v:yz[x]) st.insert(mx[v]);
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
