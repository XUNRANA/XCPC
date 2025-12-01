#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[10010];
int h[10010];
int vt[10010];
int p[10010];
int d[10010];
int f[10010][64];
int dp[10010][64];
void solve() 
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        g[i].clear();
        p[i]=0;
        d[i]=1e9;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int w;
    cin>>w;
    for(int i=1;i<=w;i++) cin>>h[i],vt[i]=0;
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        vt[x]=1;
        p[h[x]]+=1<<(i-1);
    }
    queue<int>q;
    q.push(1);
    for(int i=1;i<=n;i++) for(int j=0;j<(1<<k);j++) f[i][j]=0;
    d[1]=0;
    f[1][0]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(d[u]+1>d[v]) continue;
            if(d[u]+1<d[v]) 
            {
                d[v]=d[u]+1;
                q.push(v);
            }
            for(int st=0;st<(1<<k);st++) 
            {
                f[v][st]|=f[u][st];
                f[v][st|p[v]]|=f[u][st];
            }
        }
    }
    for(int i=1;i<=w;i++) for(int j=0;j<(1<<k);j++) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<w;i++)
    {
        for(int st=0;st<(1<<k);st++)
        {
            if(!dp[i][st]) continue;
            if(vt[i+1])
            {
                dp[i+1][st]=1;
                continue;
            }
            for(int nw=0;nw<(1<<k);nw++)
            if(f[h[i+1]][nw]) dp[i+1][st|nw]=1;
        }
    }
    int ans=0;
    for(int st=0;st<(1<<k);st++)
    if(dp[w][st]) ans=max(ans,(int)__builtin_popcount(st));
    cout<<k-ans<<"\n";
}
/*
1.深呼吸，不要紧张，慢慢读题，读明白题，题目往往比你想的简单。
2.暴力枚举:枚举什么，是否可以使用一些技巧加快枚举速度（预处理、前缀和、数据结构、数论分块）。
3.贪心:需要排序或使用数据结构（pq）吗，这么贪心一定最优吗。
4.二分：满足单调性吗，怎么二分，如何确定二分函数返回值是什么。
5.位运算：按位贪心，还是与位运算本身的性质有关。
6.数学题：和最大公因数、质因子、取模是否有关。
7.dp：怎么设计状态，状态转移方程是什么，初态是什么，使用循环还是记搜转移。
8.搜索：dfs 还是 bfs ，搜索的时候状态是什么，需要记忆化吗。
9.树上问题：是树形dp、树上贪心、或者是在树上搜索。
10.图论：依靠什么样的关系建图，是求环统计结果还是最短路。
11.组合数学：有几种值，每种值如何被组成，容斥关系是什么。
12.交互题：log(n)次如何二分，2*n 次如何通过 n 次求出一些值，再根据剩余次数求答案。
13.如果以上几种都不是，多半是有一个 point 你没有注意到，记住正难则反。
*/

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}