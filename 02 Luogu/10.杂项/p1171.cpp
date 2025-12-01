#include <bits/stdc++.h>
using namespace std;
const int N=21;// 定义城市数量
int n,dis[N][N]; 
int dp[1<<N][N];// 动态规划数组，dp[s][j] 表示当前状态为 s，且以城市 j 结尾的最短路径
int main() 
{
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>dis[i][j];
	
	// 初始化动态规划数组，所有状态的初始值设为一个大数（表示无限大）
	for(int s=0;s<(1<<n);s++) for(int j=0;j<n;j++) dp[s][j]=1e9;
	// 初始化起点到其他城市的距离，起点为城市 0
	for(int i=1;i<n;i++) // 从城市 1 到城市 N-1
	{
		dp[(1<<i)+1][i]=dis[0][i];// 设置从城市 0 到城市 i 的初始距离
	}
	// 枚举所有状态 s
	for(int s=0;s<(1<<n);s++)
	{
		if(!(s&1)) continue;// 如果状态 s 中没有包含城市 0，则跳过
		for(int i=1;i<n;i++)
		{
			if(!(s>>i&1)) continue;// 如果状态 s 中没有包含城市 i，则跳过
			for(int k=1;k<n;k++)// 遍历所有城市 i
			{
				if(k==i||!(s>>k&1)) continue; // 如果 k 和 i 相同或者状态 s 中没有包含城市 k，则跳过
				// 以 k 结尾的状态转移到以 i 结尾的状态
				if(dp[s-(1<<i)][k]+dis[k][i]<dp[s][i])// 如果从 k 转移到 i 的新路径更短
				{
					dp[s][i]=dp[s-(1<<i)][k]+dis[k][i];// 更新 dp 数组的最短路径值
				}
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
	cout<<ans<<"\n";
}

