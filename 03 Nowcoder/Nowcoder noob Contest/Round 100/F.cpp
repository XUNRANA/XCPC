#include <bits/stdc++.h>
using namespace std;
#define N 200010

int n, m;  // n表示点的数量，m表示边的数量
vector<pair<int, int>> g[N];  // 邻接表，存储图中每个点的出边
int in[N], u[N], v[N], fa[N];  // in存储每个点的度数，u和v分别存储每条边的两个端点，fa用于并查集

// 并查集查找函数，带路径压缩
int find(int x) {
    if (x == fa[x]) return x;  // 如果x是其自身的根节点，直接返回x
    return fa[x] = find(fa[x]);  // 否则递归查找根节点并压缩路径
}

// 并查集合并函数
void merge(int x, int y) {
    fa[find(x)] = find(y);  // 将x所在的集合合并到y所在的集合中
}

// 主算法逻辑
void solve() {
    cin >> n >> m;  // 读取点数n和边数m
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];  // 读取每条边的两个端点u[i]和v[i]
        in[u[i]]++;  // 更新u[i]的度数
        in[v[i]]++;  // 更新v[i]的度数
        fa[i] = i;  // 初始化并查集，每条边单独作为一个集合
    }
    for (int i = 1; i <= n; i++) g[i].clear();  // 清空邻接表
    for (int i = 1; i <= m; i++) {
        // 根据度数和节点编号给边定向
        if (in[u[i]] < in[v[i]] || (in[u[i]] == in[v[i]] && u[i] < v[i]))
            g[v[i]].push_back({u[i], i});  // 度数小或编号小的点作为出发点
        else
            g[u[i]].push_back({v[i], i});  // 度数大的点作为出发点
    }
    
    vector<pair<int, int>> vis(n + 1);  // 记录访问状态，用于标记和查找
    for (int i = 1; i <= n; i++) {
        for (auto v : g[i]) vis[v.first] = {i, v.second};  // 标记当前点的邻接点
        for (auto v : g[i]) {
            // 枚举邻接点的邻接点，寻找三元环
            for (auto v1 : g[v.first]) {
                if (vis[v1.first].first == i) {  // 如果发现三元环
                    merge(v1.second, v.second);  // 合并两个边所在的集合
                    merge(v.second, vis[v1.first].second);  // 合并与标记点的集合
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) ans += (fa[i] == i);  // 计算集合的数量
    if (ans == 1) cout << "Yes\n";  // 如果所有边都在一个集合中，输出Yes
    else cout << "No\n";  // 否则输出No
}

int main() {
    ios::sync_with_stdio(0);  // 提高输入输出的效率
    cin.tie(0); cout.tie(0);  // 解除cin和cout的绑定，进一步提高效率
    int T = 1;
    cin >> T;  // 读取测试用例的数量
    while (T--) solve();  // 对每个测试用例调用solve函数
}

