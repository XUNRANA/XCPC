#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,ans;
vector<int>g[N];
int d[N];
int f[N];
int sz[N];
int sum[N];
int vt[N];
void dfs(int u,int fa)
{
    f[u]=fa;
    sz[u]=1;//子树大小
    sum[u]=vt[u];//字数内：叶子节点+与叶子直接相连的点的个数 
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sum[u]+=sum[v];
        sz[u]+=sz[v];
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),vt[i]=0;
    for(int i=1;i<n;i++) 
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++) 
    if(g[i].size()==1) 
    {
        cnt++;
        vt[i]=1;//叶子
        vt[g[i][0]]=1;//直接相邻的点
    }
    ans=cnt*(n-cnt);
    dfs(1,0);
    for(int i=1;i<=n;i++)//枚举尾巴
    {
        int s1=0,s2=0;
        if(g[i].size()==1) continue;//叶子直接跳过
        for(auto v:g[i])//子节点的贡献
        {
            //父亲跳过
            if(v==f[i]) continue;
            //儿子和叶子节点相邻
            if(vt[v]&&g[v].size()>1) s1+=sz[v]-sum[v];
        }
        //父亲的贡献:父亲与叶子节点相邻
        if(i!=1&&vt[f[i]]&&g[f[i]].size()>1) s2+=(n-sz[i])-(sum[1]-sum[i]);
        ans+=s1+s2;
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
