#include <bits/stdc++.h>
using namespace std;
#define int long long

int fa[200010];
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1) merge(x,y);
        else cout<<(find(x)==find(y)? "Y\n":"N\n");
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