#include <bits/stdc++.h>
using namespace std;
#define int long long

int c[1010];
int x[1010];
int y[1010];
vector<int>g[1010];
int n,d;
bool dis(int i,int j)
{
    int d2=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
    return d2<=d*d;
}

bool dfs(int u)
{
    for(auto v:g[u])
    {
        if(c[v]==-1)
        {
            c[v]=c[u]^1;
            if(!dfs(v)) return 0;
        }
        else if(c[v]==c[u]) return 0;
    }
    return 1;
}
bool ck()
{
    for(int i=1;i<=n;i++)
    if(c[i]==-1)
    {
        c[i]=0;
        if(!dfs(i)) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) 
    {
        cin>>x[i]>>y[i];
        g[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(dis(i,j))
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++) c[i]=-1;
    if(ck()) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}