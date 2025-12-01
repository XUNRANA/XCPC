#include <bits/stdc++.h>
using namespace std;
#define int long long // 使用 `long long` 类型定义 `int`，确保可以处理大数
#define N 400010 // 定义数组的最大长度
vector<int> g[N]; // 邻接表存储图，`g[i]` 存储与节点 `i` 相连的所有节点
int dfn[N], low[N], stk[N], dcc[N], siz[N], cnt, tot, top; 
// `dfn` 和 `low` 用于 Tarjan 算法中的时间戳
// `stk` 用于模拟栈，保存当前的搜索路径
// `dcc` 记录每个点所属的双连通分量编号
// `siz` 记录每个双连通分量的大小（包含的节点数）
// `cnt` 记录双连通分量的数量
// `tot` 记录遍历的时间戳，用于标识节点的访问次序
// `top` 是栈顶指针

void tarjan(int x, int fa) 
{
    dfn[x] = low[x] = ++tot; // 初始化当前节点的 dfn 和 low 值，初始时两者相等
    stk[++top] = x; // 将当前节点压入栈中，用于后续回溯时处理双连通分量

    for (auto y : g[x]) // 遍历当前节点 `x` 的所有邻居 `y`
    {
        if (!dfn[y]) // 如果邻居节点 `y` 还没有被访问过
        {
            tarjan(y, x); // 递归调用 Tarjan 函数，继续深度优先搜索
            low[x] = min(low[x], low[y]); // 更新当前节点 `x` 的 low 值
            // 如果 `low[y] > dfn[x]`，说明 `(x, y)` 是一条桥，但此处并未使用该信息
        }
        else if (y != fa) // 如果邻居节点 `y` 已经被访问过且不是父节点 `fa`
        {
            low[x] = min(low[x], dfn[y]); // 更新当前节点 `x` 的 low 值
        }
    }

    if (low[x] == dfn[x]) // 如果当前节点 `x` 是一个双连通分量的根节点（即一个新的联通块）
    {
        int y;
        cnt++; // 增加双连通分量的计数
        do 
        {
            y = stk[top--]; // 从栈中弹出节点，形成一个新的双连通分量
            dcc[y] = cnt; // 记录节点 `y` 所属的双连通分量编号
            siz[cnt]++; // 增加当前双连通分量的大小（节点数）
        } while (y != x); // 直到回到当前节点 `x` 为止，完成一个双连通分量的识别
    }
}

void solve() 
{
    int n, m, u, v;
    cin >> n >> m; // 输入节点 `n` 和边 `m` 的数量
    for (int i = 1; i <= m; i++) 
    {
        cin >> u >> v; // 输入每条边的两个端点 `u` 和 `v`
        g[u].push_back(v); // 将边加入邻接表 `g`
        g[v].push_back(u); // 因为是无向图，双向加入
    }
    
    for (int i = 1; i <= n; i++) 
        if (!dfn[i]) 
            tarjan(i, i); // 如果节点 `i` 没有被访问过，执行 Tarjan 算法，识别所有桥和双连通分量
    
    vector<int> dp(n / 2 + 1, 0); // 创建 dp 数组用于动态规划，`dp[j]` 表示是否可以形成大小为 `j` 的联通块
    dp[0] = 1; // 初始条件：可以形成大小为 0 的联通块

    for (int i = 1, s = 0, sum = 0; i <= cnt; i++) 
    {
        sum += siz[i]; // 累加当前已处理的双连通分量的总大小
        for (int j = min(sum, n / 2); j >= max(s, siz[i]); j--) 
        {
            dp[j] |= dp[j - siz[i]]; // 更新 dp 数组：若 `dp[j - siz[i]]` 为真，则 `dp[j]` 也为真
            if (dp[j]) 
                s = max(s, j); // 更新当前已知的最大可行联通块大小 `s`
        }
    }

    for (int i = n / 2; i >= 0; i--) 
    {
        if (dp[i]) 
        {
            cout << i * (n - i) << "\n"; // 输出最大割集的代价，即两个联通块大小的乘积
            return; // 找到结果后立即返回
        }
    }
}

signed main() 
{
    ios::sync_with_stdio(0); // 提高 I/O 效率
    cin.tie(0); cout.tie(0); // 解绑输入输出流，提高输入输出性能
    
    int T = 1; // 测试用例数量
    // cin >> T; // 如果有多组测试用例，取消注释
    while (T--) solve(); // 执行 solve 函数
}

