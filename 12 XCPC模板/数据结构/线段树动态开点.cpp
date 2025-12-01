#include <bits/stdc++.h>
using namespace std;

// 定义 long long 类型为默认的整数类型
#define int long long
// 常量 N 表示数组大小，M 为树的最大节点数，inf 为极大值
const int N = 2e5 + 5, M = N * 60, inf = 1e9;

// 全局变量
int a[N], n, m, ls[M], rs[M], sz[M]; // 数组 a 存储输入，ls/rs 为线段树左右子节点，sz 记录节点内元素数量
int sum[M];                          // sum 数组记录线段树节点的区间和值
int nod, rt;                         // nod 为当前可用的新节点编号，rt 为线段树根节点
int msum = 0;                        // 负数部分的总和

// 更新线段树，o 表示当前节点编号，l 和 r 是区间，v 是值，t 是增量（+1 或 -1）
void modify(int &o, int l, int r, const int &v, const int &t) {
    if (!o) o = ++nod;               // 如果节点不存在，则分配新节点
    if (l == r) {                    // 如果到达叶子节点
        sz[o] += t;                  // 更新叶子节点的元素数量
        sum[o] += t * l;             // 更新叶子节点的区间和值
        return;
    }
    const int mid = (l + r) >> 1;    // 计算中点
    if (v <= mid)                    // 如果值落在左区间
        modify(ls[o], l, mid, v, t); // 递归更新左子树
    else                             // 如果值落在右区间
        modify(rs[o], mid + 1, r, v, t); // 递归更新右子树
    sz[o] = sz[ls[o]] + sz[rs[o]];   // 更新当前节点的元素数量
    sum[o] = sum[ls[o]] + sum[rs[o]]; // 更新当前节点的区间和值
}

// 在当前线段树中查询最多能取出的元素数量，s 为可用的总和
int query(int o, int l, int r, const int &s) {
    if (s >= sum[o]) return sz[o];   // 如果总和 s 足够覆盖整个节点的值，返回所有元素数量
    if (l == r) {                    // 如果到达叶子节点
        if (s > sz[o] * l)           // 如果 s 大于该节点全部元素的值
            return sz[o];            // 返回全部元素数量
        return s / l;                // 否则返回能取出的数量
    }
    const int mid = (l + r) >> 1;    // 计算中点
    if (s >= sum[ls[o]])             // 如果 s 足够覆盖左子树的总和值
        return sz[ls[o]] + query(rs[o], mid + 1, r, s - sum[ls[o]]); // 继续查询右子树
    return query(ls[o], l, mid, s);  // 否则只查询左子树
}

// 插入元素到结构中，正数插入线段树，负数加到 msum
void ins(int x) {
    if (x > 0) 
        modify(rt, 1, inf, x, 1);    // 正数更新线段树
    else 
        msum -= x;                   // 负数更新 msum
}

// 从结构中删除元素，正数从线段树中删除，负数从 msum 减去
void del(int x) {
    if (x > 0) 
        modify(rt, 1, inf, x, -1);   // 正数删除线段树
    else 
        msum += x;                   // 负数更新 msum
}

// 处理一组测试数据
void solve() {
    int n, q;                        // n 表示数组大小，q 表示查询次数
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {   // 读取数组 a，并初始化结构
        cin >> a[i];
        ins(a[i]);                   // 插入元素到结构中
    }
    while (q--) {                    // 处理 q 次查询
        int x, v;
        cin >> x >> v;               // x 为修改的索引，v 为新值
        del(a[x]);                   // 删除原来的值
        a[x] = v;                    // 更新数组 a
        ins(a[x]);                   // 插入新的值
        cout << query(rt, 1, inf, msum) + 1 << "\n"; // 输出结果
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);         // 优化输入输出
    int T = 1;                       // 测试用例数量，默认为 1
    // cin >> T;
    while (T--) solve();             // 依次处理每个测试用例
}
