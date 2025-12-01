#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<pair<int,int>>g[100010];
int a[100010];
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<int>d(n+1,0);
    vector<int>vt(n+1,0);
    priority_queue<pair<int,int>>q;
    for(int i=1;i<=n;i++) 
    if(a[i]) 
    {
        for(auto v1:g[i])
        {
            int v=v1.first;
            int w=v1.second;
            if(d[v]<d[i]+w)
            {
                d[v]=d[i]+w;
                q.push({d[v],v});
            }
        }
    }
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(auto v1:g[u])
        {
            int v=v1.first;
            int w=v1.second;
            if(d[v]<d[u]+w)
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++) 
    if(!d[i]) 
    {
        if(a[i]) cout<<"0 ";
        else cout<<"-1 ";
    }
    else cout<<d[i]<<" ";
    cout<<"\n";
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