#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int dep[200010];
int f[200010];
void dfs(int u,int fa)
{
    f[u]=fa;
    dep[u]=dep[fa]+1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
bool cmp(int x,int y)
{
    return dep[x]<dep[y];
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        vector<int>a;
        for(int i=1;i<=k;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),cmp);
        if(a.size()<=2) cout<<"YES\n";
        else 
        {
            if(dep[a[0]]==dep[a[1]]) cout<<"NO\n";
            else
            {
                int u=a[0];
                int v=a.back();
                set<int>b;
                b.insert(v);
                while(f[v]&&f[v]!=a[0])
                {
                    v=f[v];
                    b.insert(v);
                }
                vector<int>na;
                for(auto i:a) if(!b.count(i)) na.push_back(i);
                a=na;

                if(a.size()==1) cout<<"YES\n";
                else 
                {
                    int u=a[0];
                    int v=a.back();
                    set<int>b;
                    b.insert(v);
                    while(f[v]&&f[v]!=a[0])
                    {
                        v=f[v];
                        b.insert(v);
                    }
                    int f=0;
                    for(auto i:a) if(!b.count(i)) f=1;
                    if(f) cout<<"NO\n";
                    else cout<<"YES\n";
                }
            } 
        }
    }
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