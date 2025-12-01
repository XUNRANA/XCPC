#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,u,v;
vector<int>g[110];
int d[110];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        d[i]=1e9;
        cin>>u>>k;
        while(k--)
        {
            cin>>v;
            g[u].push_back(v);
        }
    }
    queue<int>q;
    q.push(1);
    d[1]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(d[v]>d[u]+1) 
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1e9) d[i]=-1;
        cout<<i<<" "<<d[i]<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
