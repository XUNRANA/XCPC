#include <bits/stdc++.h>
using namespace std;
int order[20];
bool chosen[20];
int n;
void calc(int k)
{
	if(k==n+1)
	{
		for(int i=1;i<=n;i++) cout<<order[i]<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(chosen[i]) continue;
		order[k]=i;
		chosen[i]=1;
		calc(k+1);
		chosen[i]=0;
		order[k]=0;
	}
}
int main()
{
	cin>>n;
	calc(1);
} 
/*
int order[20]：这个数组用于存储排列的元素顺序。
bool chosen[20]：这个布尔数组用于跟踪哪些元素已经被选中或处理过。
void calc(int k)：这是一个递归函数，它生成排列。k 是当前要填充的位置。
当 k 达到 n + 1 时，它意味着已经生成了一个完整的排列，然后输出这个排列。
在 calc 函数中，使用一个 for 循环来尝试放置每个可能的元素到 order 数组中，
只要这个元素还没有被选中。然后，将 chosen 数组中对应的位置设置为 true 表示
已经选择了这个元素，递归调用 calc 来填充下一个位置。
在递归返回之前，需要将 chosen 数组和 order 数组中的相应位置重置为 false 和 0，
以便在下一个递归步骤中正确处理其他排列。
在 main 函数中，首先读取输入的整数 n，然后调用 calc(1) 开始生成排列。
这段代码的目的是生成 1 到 n 的排列，并将它们输出到标准输出。
输出结果是所有可能的排列的列表。如果你有具体的问题或需要进一步的解释，请随时提问。
*/
