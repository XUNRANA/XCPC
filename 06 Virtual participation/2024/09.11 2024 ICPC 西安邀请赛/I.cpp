#include <bits/stdc++.h>
using namespace std;
#define int long long  // 定义long long类型为int的别名，方便处理大整数
#define N 25  // 定义最大n的值
#define M 100010  // 定义dp数组的大小，表示状态总数
#define inf 0x3f3f3f3f  // 定义一个极大的数，用于初始化dp数组
int n,k,m,l,r,a[N][N],b[N][N][N],dp[M];  // 定义全局变量
// `a[i][j]`表示从i到j的区间中被输入的区间所覆盖的次数
// `b[i][l][r]`表示区间包含第i位且被[l,r]完整包含的区间的数量
// `dp[i]`表示当前最大值已经覆盖的状态是i时的最小代价和

// 更新函数，选择较小的值更新
void upd(int &x,int y) 
{
	x=min(x,y);
}

void solve()
{
	cin>>n>>k>>m;  // 输入n, k, m，分别表示元素数量，最大值k和输入的区间数
	for(int i=1;i<=m;i++) 
	{
		cin>>l>>r;  // 输入每个区间的左右端点l, r
		a[l][r]++;  // 将区间[l, r]在`a`数组中标记
	}

	// 计算每个`b[i][l][r]`值
	for(int i=1;i<=n;i++)  // 遍历所有的元素i
	{
		for(int l=1;l<=i;l++)  // 遍历所有可能的左端点l
		{
			for(int r=i;r<=n;r++)  // 遍历所有可能的右端点r
			{
				for(int x=l;x<=i;x++)  // 遍历从l到i的区间
				{
					for(int y=i;y<=r;y++)  // 遍历从i到r的区间
					{
						b[i][l][r]+=a[x][y];  // 计算`b[i][l][r]`表示区间被包含的次数
					}
				}
			}
		}
	}

	// 初始化dp数组
	memset(dp,inf,sizeof dp);
	dp[0]=0;  // 初始状态（没有选取任何元素）代价为0

	// 枚举所有状态i，利用状压dp进行状态转移
	for(int i=0;i<(1<<n);i++)
	{
		vector<int>pre(n,-1),suf(n,n);  // `pre`存储左边第一个1的位置，`suf`存储右边第一个1的位置
		int now=-1,bit=0;  // `now`表示当前的状态，`bit`记录当前状态下1的个数
		for(int j=0;j<n;j++)  // 遍历每一位
		{
			if(i>>j&1) now=j,bit++;  // 如果当前位为1，记录下来
			else pre[j]=now+1;  // 否则更新左边的1的位置
		}
		now=n;
		for(int j=n-1;j>=0;j--)  // 逆向遍历每一位
		{
			if(i>>j&1) now=j;  // 如果当前位为1，更新右边的1的位置
			else
			{
				suf[j]=now-1;  // 否则更新右边的1的位置
				int x=j+1,y=pre[j]+1,z=suf[j]+1;  // 计算当前区间的左右端点
				upd(dp[i|(1<<j)],dp[i]+b[x][y][z]*max(k-bit,0ll));  // 更新状态`dp[i|(1<<j)]`
			}
		}
	}

	// 输出最终结果，即所有状态覆盖完后的最小代价
	cout<<dp[(1<<n)-1]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);  // 提高cin/cout的效率
	cin.tie(0);cout.tie(0);  // 解除cin和cout的绑定，提高输入输出效率
	int T=1;
	//cin>>T;  // 如果有多组测试用例，可以启用这一行
	while(T--) solve();  // 执行求解函数
}

