#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 400010
int ans[N];
vector<int>col[N];
int l[N],r[N],c[N];
int d[N];
int mm;
int tr[N<<2];
int tag[N<<2];
#define lc p<<1
#define rc p<<1|1

void pushup(int p)
{
    tr[p]=tr[lc]+tr[rc];
}

void pushdown(int p,int l,int r)
{
    int m=l+r>>1;
    tr[lc]+=(m-l+1)*tag[p];
    tr[rc]+=(r-m)*tag[p];
    tag[lc]+=tag[p];
    tag[rc]+=tag[p];
    tag[p]=0;
}

void update(int p,int l,int r,int x,int y,int k)
{
    if(x<=l&&r<=y)
    {
        tr[p]+=(r-l+1)*k;
        tag[p]+=k;
        return ;
    }
    pushdown(p,l,r);
    int m=l+r>>1;
    if(x<=m) update(lc,l,m,x,y,k); 
    if(y>m) update(rc,m+1,r,x,y,k); 
    pushup(p);
}

bool query(int p,int l,int r,int x,int y)
{
    if(x<=l&&y>=r) return tr[p];
    pushdown(p,l,r);
    int m=l+r>>1;
    if(x<=m&&y>m) return query(lc,l,m,x,y)|query(rc,m+1,r,x,y);
    if(x<=m) return query(lc,l,m,x,y);
    else return query(rc,m+1,r,x,y);
}

int query_l(int p,int l,int r,int x)
{
    if(l>x||!tr[p]) return 0;
    if(l==r) 
    {
        if(tr[p]) return l;
        else return 0;
    }
    pushdown(p,l,r);
    int m=l+r>>1;
    if(x>m) 
    {
        int res=query_l(rc,m+1,r,x);
        if(res>=1) return res;
    }
    return query_l(lc,l,m,x);
}

int query_r(int p,int l,int r,int x)
{
    if(r<x||!tr[p]) return mm+1;
    if(l==r) 
    {
        if(tr[p]) return l;
        else return mm+1;
    }
    pushdown(p,l,r);
    int m=l+r>>1;
    if(x<=m) 
    {
        int res=query_r(lc,l,m,x);
        if(res<=mm) return res;
    }
    return query_r(rc,m+1,r,x);
}


void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) col[i].clear();
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i]>>c[i];
        d[i]=l[i];
        d[i+n]=r[i];
        col[c[i]].push_back(i);
    }
    sort(d+1,d+n*2+1);//离散化
    mm=unique(d+1,d+2*n+1)-d-1;
    for(int i=1;i<=mm*4;i++) tag[i]=tr[i]=0;
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(d+1,d+1+mm,l[i])-d;
        r[i]=lower_bound(d+1,d+1+mm,r[i])-d;
        update(1,1,mm,l[i],r[i],1);
    }

    d[0]=-1e18;
    d[mm+1]=1e18;
    for(int i=1;i<=n;i++)
    {
        for(auto j:col[i]) update(1,1,mm,l[j],r[j],-1);

        for(auto j:col[i]) 
        {
            if(query(1,1,mm,l[j],r[j])) ans[j]=0;
            else 
            {
                int pl=query_l(1,1,mm,l[j]);
                int pr=query_r(1,1,mm,r[j]);
                ans[j]=min(1ll*d[l[j]]-d[pl],1ll*d[pr]-d[r[j]]);
            }
        }
        for(auto j:col[i]) update(1,1,mm,l[j],r[j],1);
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
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