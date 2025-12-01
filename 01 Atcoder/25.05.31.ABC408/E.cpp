#include <bits/stdc++.h>
using namespace std;
#define int long long

int u[200010];
int v[200010];
int w[200010];
int f[200010];
int n,m;
int find(int x)
{
    return x==f[x]? x:f[x]=find(f[x]);
}
void merge(int i)
{
    f[find(u[i])]=find(v[i]);
}
bool ck(int x)
{
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++) if(w[i]<=x) merge(i);
    return find(1)==find(n);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        if(!ck((1LL<<i)-1))
        {
            ans|=1ll<<i;
            for(int j=1;j<=m;j++) 
            {
                if(w[j]>>i&1) w[j]-=1ll<<i;
            }
        }
    }
    cout<<ans<<"\n";
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