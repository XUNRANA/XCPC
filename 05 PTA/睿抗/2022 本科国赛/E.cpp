#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>g[2010];
int d[2010][2010];
int f[2010];
void dfs(int u,int fa,int rt)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        d[rt][v]=d[rt][u]+1;
        dfs(v,u,rt);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        d[i][i]=0;
        dfs(i,0,i);
    }

    for(int i=1;i<=n;i++) cin>>f[i];

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(f[i]!=f[j])
            for(int k=j+1;k<=n;k++)
            {
                if(f[k]!=f[i]&&f[k]!=f[j])
                {
                    if(d[i][j]==d[i][k]&&d[i][k]==d[j][k]) ans++;

                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
