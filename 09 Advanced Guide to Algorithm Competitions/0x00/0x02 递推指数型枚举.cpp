//从1-n(n<=20)中随机选取 任意多个 ，输出所有可能方案 
#include <bits/stdc++.h>
using namespace std;
vector<int> chosen;
int n;
/*
calc(1) 被调用，此时 x 为 1。

x 不等于 n+1，所以不会进入递归出口条件。
先调用 calc(2)，然后将 2 添加到 chosen，然后再次调用 calc(2)。
calc(2) 被调用，此时 x 为 2。

x 不等于 n+1，所以不会进入递归出口条件。
先调用 calc(3)，然后将 3 添加到 chosen，然后再次调用 calc(3)。
calc(3) 被调用，此时 x 为 3。

x 等于 n+1，所以进入递归出口条件。
输出 chosen 中的元素，即 1 2 3。
然后返回上一级的递归调用，即 calc(2)。
回到 calc(2)，此时 chosen 包含元素 1 和 2。

输出 chosen 中的元素，即 1 2。
然后将 2 从 chosen 中移除。
然后返回上一级的递归调用，即 calc(1)。
回到 calc(1)，此时 chosen 包含元素 1。

输出 chosen 中的元素，即 1。
然后将 1 从 chosen 中移除。
然后返回到 main 函数。
*/
void calc(int x)
{
	if(x==n+1)
	{
		for(int i=0;i<chosen.size();i++) cout<<chosen[i]<<" ";
		cout<<endl;
		return ;
	}
	calc(x+1);
	chosen.push_back(x);
	calc(x+1);
	chosen.pop_back();
}
int main()
{
	cin>>n;
	calc(1);
}
