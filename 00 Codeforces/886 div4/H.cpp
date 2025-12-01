#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[200010];
vector<pair<int,int>>g[200010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) ans[i]=-1e18,g[i].clear();
    for(int i=1;i<=m;i++)
    {
        int u,v,d;    
        cin>>u>>v>>d;
        g[u].push_back({v,d});
        g[v].push_back({u,-d});
    }
    for(int i=1;i<=n;i++)
    if(ans[i]==-1e18)
    {
        ans[i]=0;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v1:g[u])
            {
                int v=v1.first;
                int dis=v1.second;
                if(ans[v]==-1e18)
                {
                    ans[v]=ans[u]+dis;
                    q.push(v);
                }
                else if(ans[v]!=ans[u]+dis)
                {
                    cout<<"NO\n";
                    return ;
                }
            }
        }
    }
    cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
