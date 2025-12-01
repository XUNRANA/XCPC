#include <bits/stdc++.h> // 包含所有标准库头文件
using namespace std; // 使用标准命名空间



void solve() // 主解函数
{
	map<int,vector<int>>mp;
	for(int i=1;i<=5;i++) mp[1].push_back(i),mp[2].push_back(5-i);
	for(auto i:mp)
	{
		cout<<i.first<<"\n";
		for(auto j:i.second) cout<<j<<" ";
		cout<<"\n";
 	}
}

int main() // 主函数
{
    ios::sync_with_stdio(0); // 优化输入输出
    cin.tie(0); cout.tie(0); // 取消 cin 和 cout 的绑定，提高执行效率
    int T = 1; // 定义测试用例数 T，初始化为 1
    // cin >> T; // 如果有多组测试用例，解除注释此行
    while (T--) solve(); // 逐组测试用例调用 solve 函数
}

