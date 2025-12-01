#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[200010];
int idx[9][2];
void solve() 
{
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++) p[i]=p[i-1]+(s[i]-'0');
    for(int i=0;i<9;i++) idx[i][0]=idx[i][1]=0;
    int w,q;
    cin>>w>>q;
    for(int i=1;i<=n;i++) if(i+w-1<=n)
    {
        int num=(p[i+w-1]-p[i-1])%9;
        if(!idx[num][0]) idx[num][0]=i;
        else if(!idx[num][1]) idx[num][1]=i;
    }
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int num=(p[r]-p[l-1])%9;
        int a1=1e9,a2=1e9;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if((i*num+j)%9==k)
                {
                    int a11,a22;
                    a11=idx[i][0];
                    if(i==j) a22=idx[i][1];
                    else a22=idx[j][0];
                    if(a11&&a22) 
                    {
                        if(a11<a1)
                        {
                            a1=a11;
                            a2=a22;
                        }
                        else if(a11==a1) a2=min(a2,a22);
                    }
                }
            }
        }
        if(a1!=1e9) cout<<a1<<" "<<a2<<"\n";
        else cout<<"-1 -1\n";
    }

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