#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<array<int,2>>g[10010];
int n,m,H;
int h[10010];
int vt[10010][101];
int d[10010][101];
void solve()
{
    cin>>n>>m>>H;
    for(int i=1;i<=n;i++) 
    {
        cin>>h[i];
        g[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        g[u].push_back({v,t});
        g[v].push_back({u,t});
    }
    for(int i=1;i<=n;i++) for(int j=0;j<=H;j++) d[i][j]=1e18,vt[i][j]=0;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    //点 疲劳值 最小时间
    d[1][0]=0;

    //时间 疲劳值 点
    q.push({0,0,1});
    while(!q.empty())
    {
        int t=q.top()[0];
        int hh=q.top()[1];
        int u=q.top()[2];
        q.pop();
        if(vt[u][hh]) continue;
        vt[u][hh]=1;
        for(auto v1:g[u])
        {
            int v=v1[0];
            int dt=v1[1];

            if(h[u]>h[v])//清空疲劳值
            {
                if(d[v][0]>t+dt) 
                {
                    d[v][0]=t+dt;
                    q.push({d[v][0],0,v});
                }
            }
            else
            {
                int nhh=hh+h[v]-h[u];
                if(nhh>H) continue;//超过了，不能走
                if(d[v][nhh]>t+dt)
                {
                    d[v][nhh]=t+dt;
                    q.push({d[v][nhh],nhh,v});
                }
            }
        }
    }

    for(int i=2;i<=n;i++)
    {
        int ans=1e18;
        for(int j=0;j<=H;j++) ans=min(ans,d[i][j]);
        if(ans==1e18) ans=-1;
        cout<<ans<<" ";
    }
    cout<<"\n";
}
signed main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}