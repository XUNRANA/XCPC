#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define M 400010
int a[N];
int fa[N];
unordered_map<int,int>st[N];
int n,m,q;

int is[M];
int u[M],v[M];
int op[M],x[M],y[M];
int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return ;
    if(st[fx].size()>st[fy].size())
    {
        fa[fy]=fx;
        for(auto [u,v]:st[fy]) st[fx][u]+=v;
    }
    else
    {
        fa[fx]=fy;
        for(auto [u,v]:st[fx]) st[fy][u]+=v;

        // for(auto v:st[fx]) st[fy].insert(v);
    }
}
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=m;i++) 
    {
        cin>>u[i]>>v[i];
        is[i]=0;
    }

    for(int i=1;i<=q;i++) 
    {
        cin>>op[i];
        if(op[i]==1) 
        {
            cin>>x[i];
            is[x[i]]=1;//删除第x条边
        }
        else cin>>x[i]>>y[i];
    }

    for(int i=1;i<=n;i++) 
    {
        fa[i]=i;
        st[i][a[i]]=1;
    }


    // for(int i=1;i<=n;i++) 
    // {
    //     cout<<fa[i]<<"\n";
    //     for(auto j:st[fa[i]]) cout<<j<<" ";
    //     cout<<"?\n";
    // }
    // merge(u[1],v[1]);

    // for(int i=1;i<=n;i++) 
    // {
    //     cout<<fa[i]<<"\n";
    //     for(auto j:st[fa[i]]) cout<<j<<" ";
    //     cout<<"?\n";
    // }


    for(int i=1;i<=m;i++) if(!is[i]) 
    {
        // cout<<u[i]<<" "<<v[i]<<"\n";
        merge(u[i],v[i]);
    }

    stack<int>res;
    for(int i=q;i>=1;i--)
    {
        if(op[i]==1) 
        {
            merge(u[x[i]],v[x[i]]);
        }
        else 
        {
            
            int f=find(x[i]);
            int ans=0;
            if(st[f].count(y[i]-a[x[i]])) ans=st[f][y[i]-a[x[i]]];
            if(2*a[x[i]]==y[i]) ans--;
            res.push(ans);
            // cout<<ans<<"??\n";
        }
    }
    while(res.size())
    {
        cout<<res.top()<<"\n";
        res.pop();
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