#include <bits/stdc++.h>  // 导入所有C++标准库头文件
using namespace std;
#define int long long  // 将 int 定义为 long long，确保大数情况下不会溢出

int n, m, s[300010], ans = -1e18;  // n是数组长度，m是子数组最大长度，s[]是前缀和数组，ans存储结果，初始为一个很小的值

void solve()
{
    cin >> n >> m;  // 输入 n 和 m，n表示数组的大小，m表示子数组最大长度
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i-1];  // 依次输入数组，并计算前缀和

    deque<int> q;  // 定义一个双端队列 q，用来存储前缀和数组的下标
    q.push_back(0);  // 初始时将下标 0 放入队列，表示空数组的前缀和

    for(int i = 1; i <= n; i++)  // 遍历数组的每个元素
    {
        // 移除超出窗口大小的下标（即队列中下标小于 i - m 的那些），确保窗口长度不超过 m
        while(!q.empty() && q.front() < i - m) q.pop_front();
        
        // 更新答案，通过计算 s[i] - s[q.front()]，即从 q.front() 到 i 的子数组和
        ans = max(ans, s[i] - s[q.front()]);
        
        // 维护队列的单调性，移除队列末尾比当前前缀和大的下标，确保队列中前缀和递增
        while(!q.empty() && s[q.back()] >= s[i]) q.pop_back();
        
        q.push_back(i);  // 将当前下标 i 加入队列
    }

    cout << ans;  // 输出最终的答案，最大子数组和
}

signed main()
{
    ios::sync_with_stdio(0);  // 关闭 C++ 标准输入输出的同步，加快执行速度
    cin.tie(0); cout.tie(0);  // 分离输入和输出，避免I/O阻塞，提高效率
    
    int T = 1;  // T 表示测试组数，初始化为 1
    // cin >> T;  // 如果有多组测试数据时，可以取消注释，读取T的值
    while(T--) solve();  // 依次解决每一组测试
}

