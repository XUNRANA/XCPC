#include <bits/stdc++.h>
using namespace std;
int mx,au,av,rt;
vector<pair<int,int>>g[100010];
void dfs(int u,int fa)
{
    for(auto [v,w]:g[u])
    {
        if(v==fa) continue;
        if(w==mx) au=v;
        dfs(v,u);
    }
}
void solve()
{
    int n,u,v,w;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    mx=0;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        mx=max(mx,w);
    }
    if(n==3)
    {
        vector<int>a;
        for(int i=1;i<=n;i++) if(g[i].size()==1) a.push_back(i);
        cout<<a[0]<<" "<<a[1]<<" "<<"0\n";
        return ;
    }
    if(mx==0)
    {
        for(int i=1;i<=n;i++) if(g[i].size()!=n-1)
        {
            vector<int>f(n+1,0);
            for(auto v:g[i]) f[v.first]=1;
            for(int j=1;j<=n;j++) 
            if(!f[j]&&j!=i)
            {
                cout<<i<<" "<<j<<" 0\n";
                return ;
            }
        }
    }
    for(int i=1;i<=n;i++) 
    if(g[i].size()>=2)
    {
        int f=0;
        for(auto [v,w]:g[i])
        {
            if(w==mx) 
            {
                f=1;
                av=v;
                for(auto [v1,w1]:g[i]) if(v1!=v) au=v1;
                break;
            }
        }

        if(f)
        {
            cout<<au<<" "<<av<<" "<<"0\n";
            return ;
        }
        else
        {
            dfs(i,0);
            cout<<au<<" "<<i<<" "<<"0\n";
            return ;
        }
    }
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
