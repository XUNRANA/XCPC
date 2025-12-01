#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;

int fa[200010];
int mi[200010];
int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y,int w)
{
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
    mi[fy]=min(mi[fy],mi[fx]);
    mi[fy]=min(mi[fy],w);
}
void solve()
{
    cin>>n>>m;
    vector<array<int,3>>a;
    for(int i=1;i<=n;i++) mi[i]=1e9,fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a.push_back({w,u,v});
    }
    sort(a.begin(),a.end());
    int ans=2e9;
    for(auto i:a)
    {
        merge(i[1],i[2],i[0]);
        if(find(1)==find(n))
        {
            ans=min(ans,mi[find(1)]+i[0]);
        }
    }
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