#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[310];
int d[310][310];
int fa[310];
int is[310];
int find(int x)
{
    return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
void solve() 
{
    int n,m,k,t,u,v,w;
    cin>>n>>m>>k;
    cin>>t;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e18;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    for(int i=1;i<=k;i++) 
    {
        cin>>a[i];
        is[a[i]]=1; 
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    vector<array<int,3>>b;
    
    for(int i=1;i<=k;i++)
    {
        for(int j=i+1;j<=k;j++)
        {
            if(d[a[i]][a[j]]!=1e18)
            {
                b.push_back({d[a[i]][a[j]],i,j});
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(!is[i])
        {
            int mi=1e18;
            for(int j=1;j<=k;j++) mi=min(mi,2*d[i][a[j]]);
            mx=max(mx,mi);
        }
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(b.begin(),b.end());
    int cnt=0;
    for(auto i:b)
    {
        int w=i[0];
        int u=i[1];
        int v=i[2];
        if(find(u)==find(v)) continue;
        merge(u,v);
        mx=max(mx,w);
        cnt++;
        if(cnt==k-1) break;
    }
    
    if(cnt!=k-1) mx=1e18;

    if(mx==1e18||!t) cout<<"-1\n";
    else cout<<(mx+t-1)/t<<"\n";
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