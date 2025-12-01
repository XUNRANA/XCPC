#include <bits/stdc++.h>  // 导入所有常用的C++标准库头文件
using namespace std;

int l, r;  // 输入的区间左右端点
int tot;  // 节点总数计数器
int cur, id[500];  // cur表示当前深度，id数组存储每个深度的节点编号
vector<pair<int, int>> e[500];  // 邻接表存储图中的边，pair表示（目标节点编号，边的类型）

// 获取某个深度 de 对应的节点编号，如果该深度的节点尚未生成，则生成它
int getid(int de) {
    while (cur <= de) {  // 如果当前深度 cur 小于目标深度 de，生成新的节点
        tot++;  // 节点总数加一
        if (cur > 0) {  // 如果 cur 大于0，连接当前节点和上一层的节点
            e[tot].emplace_back(id[cur - 1], 0);  // 添加一条类型为0的边
            e[tot].emplace_back(id[cur - 1], 1);  // 添加一条类型为1的边
        }
        id[cur++] = tot;  // 当前深度 cur 的节点编号为 tot，并递增 cur
    }
    return id[de];  // 返回目标深度 de 对应的节点编号
}

// 深度优先搜索，根据深度 de 和区间 [l, r]，递归生成图中的节点与边
int dfs(int de, int l, int r, int s, int t) {
    if (s <= l && r <= t)  // 如果当前区间完全包含在目标区间 [s, t] 内
        return getid(de);  // 返回当前深度的节点编号
    
    int p = ++tot, mid = (l + r) >> 1;  // 创建新节点 p，计算区间中点 mid
    if (s < mid)  // 如果左半区间 [l, mid) 与目标区间有交集
        e[p].emplace_back(dfs(de - 1, l, mid, s, t), 0);  // 对左半区间递归
    if (t > mid)  // 如果右半区间 (mid, r] 与目标区间有交集
        e[p].emplace_back(dfs(de - 1, mid, r, s, t), 1);  // 对右半区间递归
    return p;  // 返回新生成的节点编号 p
}

// 主解决函数
void solve() {
	// 32+16+4+1=53
	// 128+64+32+14=236
    cin >> l >> r;  // 输入区间 [l, r]
    tot = 1;  // 初始化节点总数
    for (int i = 0; i <= 20; i++) {  // 遍历可能的深度 i
        int l2 = (1 << i), r2 = (1 << (i + 1));  // 计算2^i和2^(i+1)
        l2 = max(l2, l);  // 更新左端点为 l 和 2^i 中较大的一个
        r2 = min(r2, r + 1);  // 更新右端点为 r+1 和 2^(i+1) 中较小的一个
        
        if (l2 < r2)  // 如果区间有效
            e[1].emplace_back(dfs(i, (1 << i), 1 << (i + 1), l2, r2), 1);  // 递归生成节点并添加边
    }

    cout << tot << "\n";  // 输出总的节点数
    for (int i = 1; i <= tot; i++) {  // 遍历所有节点
        cout << e[i].size() << ' ';  // 输出节点 i 的边数量
        for (auto j : e[i])  // 遍历节点 i 的每条边
            cout << j.first << ' ' << j.second << ' ';  // 输出边的目标节点和类型
        cout << "\n";  // 换行
    }
}

int main() {
    ios::sync_with_stdio(0);  // 关闭同步以加快输入输出速度
    cin.tie(0); cout.tie(0);  // 解绑定 cin 和 cout，以避免不必要的刷新操作
    int T = 1;  // 测试用例数量
    // cin >> T;  // 如果有多组测试，取消此行注释以读取T
    while (T--) solve();  // 对每组测试用例调用 solve 函数
}

