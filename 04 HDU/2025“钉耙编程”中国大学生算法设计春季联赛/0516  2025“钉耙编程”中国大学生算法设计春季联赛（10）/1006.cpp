#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x;
vector<pair<int,int>>g[200010];
int d[200010][3];
int vt[200010][3];
void solve() 
{
    cin>>n>>m>>x;
    for(int i=1;i<=2*n;i++) g[i].clear();
    for(int i=1;i<=n;i++) 
    {
        int c;
        cin>>c;
        g[i].push_back({c+n,x});
        g[c+n].push_back({i,0});
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
    }
    for(int i=1;i<=2*n;i++) for(int j=0;j<3;j++) 
    {
        vt[i][j]=0;
        d[i][j]=1e18;
    }

    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    d[1][0]=0;
    q.push({0,1,0});
    while(!q.empty())
    {
        int u=q.top()[1];
        int l=q.top()[2];
        // cout<<d[u][l]<<" "<<u<<" "<<l<<"?\n";
        q.pop();
        if(vt[u][l]) continue;
        vt[u][l]=1;
        for(auto v1:g[u])
        {
            int v=v1.first;
            int w=v1.second;
            int ll=1;
            if(u>n) ll=0;
            if(d[v][(l+ll)%3]>d[u][l]+w)
            {
                // cout<<d[u][l]<<" "<<w<<" "<<u<<" "<<l<<" "<<v<<" "<<l+1<<" ?\n";
                d[v][(l+ll)%3]=d[u][l]+w;
                q.push({d[v][(l+ll)%3],v,(l+ll)%3});
            }
        }
    }
    // cout<<d[1][0]<<" "<<d[1][1]<<" "<<d[1][2]<<"??\n";
    if(d[n][0]==1e18) cout<<"-1\n";
    else cout<<d[n][0]<<"\n";
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