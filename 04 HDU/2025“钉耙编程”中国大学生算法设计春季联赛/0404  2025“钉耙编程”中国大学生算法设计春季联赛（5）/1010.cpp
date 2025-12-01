#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<pair<int,int>>g[500010];
int s[500010][2];
void dfs(int u,int fa)
{
    for(auto [v,w]:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        if(w&1) 
        {
            s[u][1]+=s[v][0];
            s[u][0]+=s[v][1];
        }
        else 
        {
            s[u][1]+=s[v][1];
            s[u][0]+=s[v][0];
        }
    }
}
int ans;
int C(int a)
{
    return a*(a-1)/2;
}
void dfs1(int u,int fa)
{
    // cout<<u<<" "<<s[u][1]<<" "<<s[u][0]<<"?\n";
    // cout<<u<<" "<<3*s[u][1]<<" "<<s[u][1]*(s[u][0]-1)*2<<"\n";
    ans+=3*(s[u][0]-1);
    // ans+=s[u][1]*(s[u][0]-1)*6;
    ans+=C(s[u][0]-1)*2;

    for(auto [v,w]:g[u]) 
    {
        if(v==fa) continue;
        int t1=s[u][1];
        int t0=s[u][0];
        int tt1=s[v][1];
        int tt0=s[v][0];

        if(w&1)
        {
            s[u][0]-=s[v][1];
            s[u][1]-=s[v][0];

            s[v][1]+=s[u][0];
            s[v][0]+=s[u][1];
        }
        else
        {
            s[u][0]-=s[v][0];
            s[u][1]-=s[v][1];
            
            s[v][1]+=s[u][1];
            s[v][0]+=s[u][0];
        }
        dfs1(v,u);
        s[u][1]=t1;
        s[u][0]=t0;
        s[v][1]=tt1;
        s[v][0]=tt0;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        s[i][0]=1;
        s[i][1]=0;
        g[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w&1});
        g[v].push_back({u,w&1});
    }

    dfs(1,0);
    // for(int i=1;i<=n;i++) 
    // {
        // cout<<i<<" "<<s[i][0]<<" "<<s[i][1]<<"\n";
    // }
    ans=n;
    dfs1(1,0);
    cout<<ans<<"\n";
    
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}