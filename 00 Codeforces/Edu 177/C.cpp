#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
int n,fa[100010];
int p[100010];
int d[100010];
int sz[100010];
int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
}

void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=0;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) merge(i,p[i]);
    for(int i=1;i<=n;i++) sz[find(i)]++;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=sz[find(d[i])];
        sz[find(d[i])]=0;
        cout<<ans<<" ";
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