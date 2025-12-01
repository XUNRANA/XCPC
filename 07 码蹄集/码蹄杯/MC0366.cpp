#include <bits/stdc++.h>
using namespace std;
int fa[250010];
int sz[250010];
int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return ;
    fa[fx]=fy;
    sz[fy]+=sz[fx];
}
int cnt[250010];
int dp[250010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
  
    // bitset<250010>dp;
    dp[0]=1;
    for(int i=1;i<=n;i++) if(fa[i]==i) cnt[sz[i]]++;
    
    for(int i=1;i<=n;i++)
    if(cnt[i])
    {
        int x=1;
        while(cnt[i]>=x)
        {
            cnt[i]-=x;
            for(int j=250000;j>=x*i;j--) dp[j]|=dp[j-x*i];
            // dp|=dp<<(x*i);
            x*=2;
        }
        if(cnt[i]) 
        {
            for(int j=250000;j>=cnt[i]*i;j--) dp[j]|=dp[j-cnt[i]*i];
            // dp|=dp<<(cnt[i]*i);
        }
    }

    long long ans=0;
    for(int i=0;i<=n/2+1;i++) if(dp[i]) ans=max(ans,1ll*i*(n-i));
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
