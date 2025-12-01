#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
vector<int>g[N];
int dep[N],fa[N][22],lg[N];
void dfs(int u,int f)
{
	fa[u][0]=f;//fa[u][i]表示u的2^i祖先 
	dep[u]=dep[f]+1;//深度 
	for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];//u的2^i祖先等于2^(i-1)祖先的2^(i-1)祖先 
	for(auto i:g[u])
	{
		if(i==f) continue;
		dfs(i,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=fa[u][lg[dep[u]-dep[v]]-1];//跳到同一层 
	if(u==v) return u;
	for(int k=lg[dep[u]]-1;k>=0;k--) if(fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];//跳到lca的下一层 
	return fa[u][0];
}
bool cmp(int x,int y)
{
    return dep[x]>dep[y];
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        vector<int>a;
        for(int i=1;i<=k;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),cmp);
        if(a.size()<=2) cout<<"YES\n";
        else
        {
            int u=a[0];
            int v=a[1];
            int p=-1;
            for(int i=1;i<a.size();i++)
            {
                v=a[i];
                if(lca(u,v)!=v)
                {
                    p=lca(u,v);
                    break;
                }
            }
            if(p==-1) cout<<"YES\n";
            else
            {        
                int f=0;
                for(auto i:a)
                {
                    if(!(lca(i,u)==i&&lca(i,v)==p)&&!(lca(i,v)==i&&lca(i,u)==p))
                    {
                        f=1;
                        break;
                    }
                }
                if(f) cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}