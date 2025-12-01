#include <bits/stdc++.h>
using namespace std;
vector<int>g[100010];
int in[100010];
int dp[100010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>dp[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        in[v]++;
        g[u].push_back(v);
    }
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.top();
        cout<<u<<" ";
        q.pop();
        for(auto v:g[u]) 
        {
            dp[v]+=dp[u];
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    cout<<"\n";
    for(int i=1;i<=n;i++) if(!g[i].size()) cout<<dp[i]<<" ";
    cout<<"\n";
    // for(int i=1;i=)
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
