#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],vt[100010],ans;
vector<int>g[100010];
int is(int x)
{
    int t=sqrt(x);
    if(t*t==x) return 1;
    else return 0;
}
void dfs(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        if(is(a[u]*a[v])&&!vt[v]&&!vt[u])
        {
            vt[v]=vt[u]=1;
            ans+=2;
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
