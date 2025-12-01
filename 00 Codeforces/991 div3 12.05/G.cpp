#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,u,v;
vector<int>g[200010];
int d[200010];
int ans;
int dfs(int u,int fa)
{
    int m1=-1,m2=-1;//最大、次大链长度
    for(auto v:g[u])
    {
        if(v==fa) continue;
        int len=dfs(v,u);
        if(len>m1) m2=m1,m1=len;
        else if(len>m2) m2=len; 
    }
    int res=d[u];//经过u点的链
    if(m2==-1) res=max(res,res+m1);
    else res=max(res,res+m1+m2);
    // cout<<u<<" "<<m1<<" "<<m2<<'\n';
    ans=max(ans,res);
    return max(d[u],m1+d[u]);
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),d[i]=-2;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    ans=-1e18;
    dfs(1,0);
    cout<<ans+2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
