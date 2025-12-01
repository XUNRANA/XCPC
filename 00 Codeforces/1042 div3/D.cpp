#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int is[200010];
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
    if(n==2) 
    {
        cout<<"0\n";
        return ;
    }
    int sum=0;
    for(int i=1;i<=n;i++) 
    if(g[i].size()==1) 
    {
        is[i]=1;
        sum++;
    }
    else is[i]=0;

    int ans=sum;
    for(int i=1;i<=n;i++)
    {
        int res=sum;
        for(auto v:g[i]) if(is[v]) res--;
        ans=min(ans,res);
    }
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