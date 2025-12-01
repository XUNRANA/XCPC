#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
vector<int>g[200010];
int sz[200010];
int f[200010];
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int inv(int x)
{
    return ksm(x,P-2);
}
void dfs(int u,int fa)
{
    sz[u]=1;
    f[u]=fa;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void solve()
{
    int n,u,v;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==1) cout<<n+n-1<<" ";
        else
        {
            int ans=0;
            vector<int>c;
            for(auto v:g[i]) 
            {
                if(v==f[i]) 
                {
                    ans=(ans+(n-sz[i])*(n-(n-sz[i]))%P+P)%P;
                    c.push_back(n-sz[i]);
                }
                else 
                {
                    ans=(ans+sz[v]*(n-sz[v])%P+P)%P;
                    c.push_back(sz[v]);
                }
            }

            int res=(n-1)*(n-1)%P*n%P;
            for(int j=0;j<c.size();j++) 
            {
                res=(res-c[j]*c[j]%P*(n-c[j])%P+P)%P;
                res=(res-c[j]*c[j]%P*(n-1-c[j])%P+P)%P;
                res=(res-c[j]*c[j]%P*(n-1-c[j])%P+P)%P;
                res=(res-c[j]*c[j]%P*c[j]%P+P)%P;
            }
            cout<<ans+1<<" "<<res<<"\n";
            cout<<(ans+res-n+P)%P<<" ";
        }
    }
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}