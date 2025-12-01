#include <bits/stdc++.h>
using namespace std;
#define P 998244353
#define int long long
int n,u,v,dep[1000010],cnt[1000010],cnt1[1000010];
vector<int>g[1000010];
int ans,p;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int inv(int x)
{
    return ksm(x,P-2);
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    cnt1[dep[u]]++;
    if(g[u].size()==1&&u!=1) cnt[dep[u]]++;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(cnt[i])
        {
            ans=(ans+(1-p+P)%P*(i-1)%P*cnt[i]%P*inv(cnt1[i])%P)%P;
            p=(p+(1-p+P)%P*cnt[i]%P*inv(cnt1[i])%P)%P;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
}
