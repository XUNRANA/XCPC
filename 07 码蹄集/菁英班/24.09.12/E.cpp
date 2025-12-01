#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int v[300], top; // 存储选中的节点，top为计数器

// 定义边的结构体
struct edge
{
    int x; // 边的起点
    int y; // 边的终点
    int w; // 边的权重
    // 重载小于运算符，按边的权重进行比较
    bool operator<(const edge &b) const
    {
        if (w != b.w)
            return w < b.w;
    }
} e[200005]; // 存储所有边

// 定义并查集节点的结构体
struct node
{
    int f[20005]; // 并查集数组，f[i]表示节点i的父节点
    int a, b; // 临时变量用于存储节点

    // 查找x的根节点（路径压缩）
    inline int find(int x)
    {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    // 合并两个节点所在的集合
    inline void merge(int i)
    {
        a = find(e[i].x); // 找到边i的起点的根
        b = find(e[i].y); // 找到边i的终点的根
        if (a != b)
        {
            f[b] = a; // 合并两个集合
        }
    }
} ff[540], t; // ff存储多个分块的并查集，t是临时并查集

// 检查并查集是否能连通选中的所有节点
int check(node &b)
{
    int i, j;
    for (i = 1; i < top; i++)
    {
        if (b.find(v[i]) != b.find(v[i + 1]))
        {
            return 0; // 如果两个节点不连通，返回0
        }
    }
    return 1; // 所有节点连通，返回1
}

// 二分查找能连通所有选中节点的最小块
int find_block(int n)
{
    int l = 0, r = n + 1, m;
    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (check(ff[m]))
            r = m; // 如果该块可以连通所有节点，向左缩小范围
        else
            l = m; // 否则向右
    }
    return l;
}

int f[20005]; // 并查集数组

// 查找并查集的根节点（路径压缩）
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{
    register int n, m, k, x, now = 1, i, j, y, q, l, r, p, c, a, b, siz;
    
    // 输入n个点，m条边，q个查询
    scanf("%d%d%d", &n, &m, &q);

    // 输入每条边的起点、终点和权重
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    }

    // 按权重对边进行排序
    sort(e + 1, e + m + 1);

    j = 1;
    for (i = 1; i <= n; i++)
        f[i] = i; // 初始化并查集，自己是自己的父节点

    // 遍历每条边
    for (i = 1; i <= m; i++)
    {
        a = find(e[i].x); // 找到边的起点的根
        b = find(e[i].y); // 找到边的终点的根
        e[j] = e[i]; // 保留这条边
        if (a != b) // 如果两个点不在同一个集合
        {
            f[b] = a; // 合并集合
            j++;
        }
    }

    m = j - 1; // 重新确定边的数量
    siz = max(10, (int)(sqrt(m / 3))); // 确定分块大小

    // 初始化并查集
    for (i = 1; i <= m; i++)
    {
        t.f[i] = i;
    }

    ff[0] = t; // 初始化第一个块

    // 将边按块处理
    for (i = 1; i <= m; i++)
    {
        t.merge(i); // 合并边
        if (i % siz == 0)
        {
            ff[i / siz] = t; // 每个块保存当前的并查集状态
        }
    }

    // 处理q个查询
    while (q--)
    {
        scanf("%d%d%d%d", &l, &r, &p, &c); // 输入查询参数
        top = 0;
        i = l / p * p + c;
        if (i < l)
            i += p;

        // 找到符合条件的节点
        for (; i <= r; i += p)
        {
            top++;
            v[top] = i;
        }

        // 找到能连通这些节点的最小块
        x = find_block(m / siz);
        t = ff[x]; // 取出这个块的并查集

        // 继续合并后面的边，直到找到可以连通所有节点的边
        for (i = x * siz + 1; i <= m; i++)
        {
            t.merge(i);
            if (check(t)) // 如果所有节点连通
            {
                printf("%d\n", e[i].w); // 输出当前边的权重
                break;
            }
        }
        if (i > m)
            puts("error"); // 如果没有找到，输出错误
    }
}

