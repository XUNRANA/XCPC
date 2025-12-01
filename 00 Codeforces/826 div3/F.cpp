#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int i,l,r,c;
}a[200010];
bool cmp1(node a1,node a2)
{
    if(a1.l==a2.l) return a1.r<a2.r;
    return a1.l<a2.l;
}
int ans[200010];
void solve() 
{
    int n;
    cin>>n;
    a[0]={-2000000000,-2000000000,0,0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r>>a[i].c;
        a[i].i=i;
    }
    sort(a+1,a+1+n,cmp1);
    a[n+1]={2000000000,2000000000,0,0};
    int mx1=-1e18;//最靠右
    int mx2=-1e18;
    int mt,r;
    for(int i=1;i<=n;i++)
    {
        if(a[i].c!=a[i-1].c)
        {
            r=i+1;
            while(a[i].c==a[r].c) r++;//找右边线段
        }
        //找左边线段
        if(a[i].r>mx1)
        {
            if(a[i].c!=mt) 
            {
                mx2=mx1;//颜色不同、最靠右
                mt=a[i].c;
            }
            mx1=a[i].r;
        }
        else if(a[i].r>mx2&&a[i].c!=mt) mx2=a[i].r;
        //左边、、右边
        ans[a[i].i]=min(max(a[i].l-(a[i].c==mt? mx2:mx1),0ll),max(a[r].l-a[i].r,0ll));
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