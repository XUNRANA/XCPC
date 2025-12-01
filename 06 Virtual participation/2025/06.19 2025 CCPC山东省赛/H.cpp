#include <bits/stdc++.h>
using namespace std;

#define int long long
struct node
{
    int u,v,w,id;
}a[200010];

int fa[200010];
int u[200010];
int v[200010];
int w[200010];
bool cmp(node a1,node a2)
{
    return a1.w<a2.w;
}
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
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) 
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        u[i]=a[i].u;
        v[i]=a[i].v;
        w[i]=a[i].w;
        a[i].id=i;
    }



    for(int i=1;i<=n;i++) fa[i]=i;
    sort(a+1,a+1+m,cmp);
    vector<int>b;//n-1 
    for(int i=1;i<=m;i++)
    {
        if(find(a[i].u)==find(a[i].v)) continue;
        merge(a[i].u,a[i].v);
        b.push_back(a[i].id);
    }




    
    for(int i=1;i<=n;i++) fa[i]=i;
    vector<int>ans;
    long long res=0;
    for(int i=0;i<n-1;i++)
    {
        int j=b[i];
        if(w[j]<=1)
        {
            merge(u[j],v[j]);
            ans.push_back(j);
            res+=w[j];
        }
        else
        {
            if(i<n-1-k)
            {
                merge(u[j],v[j]);
                ans.push_back(j);
                res+=w[j];
            }
        }
    }
    

    vector<array<int,2>>c;
    for(int i=1;i<n;i++) 
    if(find(i)!=find(i+1))
    {
        c.push_back({i,i+1});
        merge(i,i+1);
        res++;
    }

    cout<<c.size()<<"\n";
    for(auto i:c) cout<<i[0]<<" "<<i[1]<<"\n";
    cout<<res<<"\n";
    
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(j<ans.size()) cout<<ans[j++]<<" ";
        else cout<<(++m)<<" ";
    }
    cout<<"\n";
} 

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}

