#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_VAL = 1000005; // 数值最大值
// 节点规划:
// 1 ~ n: 真实点
// n + 1 ~ n + MAX_VAL: 数值点 (偏移量 N)
// n + MAX_VAL + 1 ~ ...: 质数点 (偏移量 N + MAX_VAL)
// 总节点数估算: 2e5 + 1e6 + 1e6 ≈ 2.2e6

// 预处理最小质因子 (Linear Sieve)
int min_prime[MAX_VAL];
void sieve() {
    vector<int> primes;
    for (int i = 2; i < MAX_VAL; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > min_prime[i] || i * p >= MAX_VAL) break;
            min_prime[i * p] = p;
        }
    }
}

// 邻接表
// 为了节省内存和时间，我们用 vector<pair<int, int>>
vector<pair<int, int>> adj[2500005]; 
int dist[2500005];
int a[200005];
bool val_exists[MAX_VAL]; // 记录哪些数值在输入中出现过，优化建图

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int n, k, s;
    if (!(cin >> n >> k >> s)) return 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        val_exists[a[i]] = true;
    }

    // 定义偏移量
    int OFFSET_VAL = n;
    int OFFSET_PRIME = n + MAX_VAL;

    // --- 建图 ---
    
    // 1. 真实点 <-> 数值点 (权值 0)
    for (int i = 1; i <= n; ++i) {
        int val_node = OFFSET_VAL + a[i];
        adj[i].push_back({val_node, 0});
        adj[val_node].push_back({i, 0});
    }

    // 遍历所有存在的数值，建立 数值点<->数值点(XOR) 和 数值点<->质数点(GCD) 的边
    for (int v = 1; v < MAX_VAL; ++v) {
        if (!val_exists[v]) continue; 

        int u_node = OFFSET_VAL + v;

        // 2. GCD 边: 数值点 -> 质数点 (权值 1), 质数点 -> 数值点 (权值 0)
        int temp = v;
        while (temp > 1) {
            int p = min_prime[temp];
            int p_node = OFFSET_PRIME + p;
            
            adj[u_node].push_back({p_node, 1}); // v -> p cost 1
            adj[p_node].push_back({u_node, 0}); // p -> v cost 0
            
            while (temp % p == 0) temp /= p;
        }

        // 3. XOR 边: 数值点 -> 数值点 (权值 1)
        // 只需要遍历 1 到 k
        for (int x = 1; x <= k; ++x) {
            int target_val = v ^ x;
            if (target_val < MAX_VAL && val_exists[target_val]) {
                int target_node = OFFSET_VAL + target_val;
                adj[u_node].push_back({target_node, 1});
            }
        }
    }

    // --- 0-1 BFS ---
    memset(dist, 0x3f, sizeof(dist));
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }

    // --- 输出 ---
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << -1 << (i == n ? "" : " ");
        else cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}