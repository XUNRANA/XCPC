#include <bits/stdc++.h> // 包含所有标准库头文件
using namespace std; // 使用标准命名空间

const int N=5e3+10, M=5e5+10; // 定义常量 N 和 M，N 为最大节点数，M 为 bitset 的大小
map<int, vector<int>> mp; // 定义一个 map，用于存储每个数的插入位置

struct SGT // 定义线段树结构体
{
    vector<int> t[N*4]; // 定义线段树数组，每个节点保存一个向量，用于存储区间内的数
    
    // 插入函数，用于在区间内插入元素 x
    void ins(int p, int l, int r, int ql, int qr, int x)
    {
        if (ql <= l && r <= qr) // 如果当前区间完全在插入区间 [ql, qr] 内
        {
            t[p].push_back(x); // 将元素 x 插入当前节点 p 的向量中
            return; // 结束当前递归
        }
        int m = l + r >> 1; // 计算中点 m
        if (ql <= m) ins(p * 2, l, m, ql, qr, x); // 如果插入区间左端点在左半区间内，递归左子区间
        if (qr > m) ins(p * 2 + 1, m + 1, r, ql, qr, x); // 如果插入区间右端点在右半区间内，递归右子区间
    }
    
    // 解决函数，用于处理查询区间内的所有元素
    void solve(int p, int l, int r, bitset<M> f)
    {
        bitset<M> g = f; // 复制 f 到局部变量 g，表示当前节点的状态集合
        for (int x : t[p]) g |= g << x; // 遍历当前节点的每个数，将它们加入集合 g 中
        if (l == r) // 如果到达叶子节点
        {
            cout << g.count() - 1 << "\n"; // 输出集合 g 中的 1 的个数减 1，即为不同子集的数量
            return; // 结束当前递归
        }
        else
        {
            int m = l + r >> 1; // 计算中点 m
            solve(p * 2, l, m, g); // 递归处理左子区间
            solve(p * 2 + 1, m + 1, r, g); // 递归处理右子区间
        }
    }
} sgt; // 定义线段树实例 sgt

void solve() // 主解函数
{
    int n, op, x; // 定义整数 n 表示操作数，op 表示操作类型，x 表示操作数值
    cin >> n; // 输入操作数 n
    for (int i = 1; i <= n; i++) // 遍历每个操作
    {
        cin >> op >> x; // 输入操作类型 op 和数值 x
        if (op == 1) // 如果操作类型为 1，表示插入操作
        {
            mp[x].push_back(i); // 将 x 的插入位置 i 加入到 map 的对应向量中
        }
        else // 如果操作类型为 2，表示删除操作
        {
            int t = mp[x].back(); // 获取 x 的最后插入位置 t
            sgt.ins(1, 1, n, t, i - 1, x); // 将 x 插入区间 [t, i-1]，调用线段树插入函数
            mp[x].pop_back(); // 弹出 x 的最后插入位置
        }
    }
    
    for (auto x : mp) // 遍历尚未匹配的插入操作
    {
    	int cnt=0;
        for (auto y : x.second) 
		{
			sgt.ins(1, 1, n, y, n, x.first); // 将尚未匹配的 x 插入区间 [y, n]
		}
    }
    
    bitset<M> f; // 定义一个 bitset 类型的集合 f
    f[0] = 1; // 初始化 f，表示当前状态包含 0
    sgt.solve(1, 1, n, f); // 调用线段树的 solve 函数，开始处理查询
}

int main() // 主函数
{
    ios::sync_with_stdio(0); // 优化输入输出
    cin.tie(0); cout.tie(0); // 取消 cin 和 cout 的绑定，提高执行效率
    int T = 1; // 定义测试用例数 T，初始化为 1
    // cin >> T; // 如果有多组测试用例，解除注释此行
    while (T--) solve(); // 逐组测试用例调用 solve 函数
}

