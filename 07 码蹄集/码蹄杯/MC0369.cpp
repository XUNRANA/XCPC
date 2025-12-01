#include <bits/stdc++.h>
using namespace std;
#define int long long

int in[100010];
int vt[100010];

vector<int>g[100010];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,2>>a;
    for(int i=1;i<=m;i++) 
    {
        int u,v;
        cin>>u>>v;
        a.push_back({u,v});
        in[v]++;
        in[u]++;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(in[i]>2)
        {
            int x=in[i];
            ans+=x*(x-1)/2*(x-2)/3;
        }
    }
    for(auto i:a)
    {
        ans+=(in[i[0]]-1)*(in[i[1]]-1);
        if(in[i[0]]<in[i[1]]||(in[i[0]]==in[i[1]]&&in[0]<in[1])) g[i[0]].push_back(i[1]);
        else g[i[1]].push_back(i[0]);
    }

    int s=0;
    for(int i=1;i<=n;i++)
    {
        for(auto v:g[i]) vt[v]=1;

        for(auto v:g[i])
        {
            for(auto u:g[v])
            {
                if(vt[u]) s++;
            }
        }

        for(auto v:g[i]) vt[v]=0;
    }
    
    // cout<<s<<"?\n";

    cout<<ans-2*s<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
