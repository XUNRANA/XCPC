#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<pair<int,int>>g[100010];
int t,r,n,m;
double dp[1<<18][18];
int d[100010];
int d1[18][19];
int vt[100010];
int a[18];
int p[18];
void dij(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=1;i<=n;i++) d[i]=1e18,vt[i]=0;
    d[s]=0;
    q.push({d[s],s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v1:g[u])
        {
            int v=v1.first;
            int w=v1.second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
void solve() 
{
    cin>>t>>r;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++) cin>>a[i]>>p[i];
    for(int i=0;i<k;i++)
    {
        dij(a[i]);
        for(int j=i+1;j<k;j++) d1[i][j]=d1[j][i]=d[a[j]];
        d1[i][k]=d[n];
    }

    dij(1);
    if(d[n]==1e18)
    {
        cout<<"-1\n";
        return ;
    }

    double ans=1.0*d[n]/t;
    // printf("%.6f\n",ans);
    for(int i=0;i<1<<k;i++) for(int j=0;j<k;j++) dp[i][j]=1e18;

    
    for(int i=(1<<k)-1;i>=1;i--)
    {
        for(int j=0;j<k;j++) 
        if(i>>j&1)//当前走到的点
        {
            dp[i][j]=0.01*(100-p[j])*d1[j][k]/r+0.01*p[j]*d1[j][k]/t;
            for(int l=0;l<k;l++)//下一个要走的点
            {
                if(l==j) continue;
                if(i>>l&1) continue;
                dp[i][j]=min(dp[i][j],0.01*(100-p[j])*d1[j][k]/r+0.01*p[j]*(1.0*d1[j][l]/t+dp[i+(1<<l)][l]));
            }
        }
    }
    for(int i=0;i<k;i++)
    ans=min(ans,dp[1<<i][i]+1.0*d[a[i]]/t);
    printf("%.6f\n",ans);
}


signed main() 
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
