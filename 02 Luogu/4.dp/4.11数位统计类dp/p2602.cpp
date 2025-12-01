#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[10][2];// 记录数字 0-9 在 [a-1, b] 范围内出现的次数
int f[15];// 记录 i 位数中每个数字 0-9 出现的次数累积和 
int p[15];// 记录 10 的 i 次方的值
int num[15];// 用于存储数字 x 的各个位数
void init()
{
	p[0]=1;// 初始化 10 的 0 次方为 1
	for(int i=1;i<15;i++) 
	{
		f[i]=f[i-1]*10+p[i-1];// 计算 f[i]，表示 i 位数中每个数字出现的次数累计和
		p[i]=p[i-1]*10;
	}
}
void fx(int x,int fx)
{
	int tot=0;// 记录数字 x 的位数
	int tmp=x;// 临时变量，用于处理 x 的值
	while(x)
	{
		num[++tot]=x%10;// 将 x 的各个位数从低到高存入 num 数组
		x/=10;
	}
	//1234
	//4321存储 
	//1234遍历 
	for(int i=tot;i>=1;i--)
	{
		for(int j=0;j<10;j++) cnt[j][fx]+=num[i]*f[i-1]; // 累加当前位前的所有位的贡献
		for(int j=0;j<num[i];j++) cnt[j][fx]+=p[i-1]; // 当前位数可以出现的数字贡献
		tmp-=num[i]*p[i-1];    // 减去当前位的贡献，处理剩下的部分
		cnt[num[i]][fx]+=tmp+1;// 加上当前位及其之后位的贡献
		//1234 去掉1还得加上1000-1234===234+1 
		cnt[0][fx]-=p[i-1];    // 修正由于多计算的前导 0 的贡献
		//000x
		//00xx 
		//0xxx 
	}
}
void solve()
{
	int a,b;
	cin>>a>>b;
	fx(a-1,0);
	fx(b,1);
	for(int i=0;i<10;i++) cout<<cnt[i][1]-cnt[i][0]<<" ";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
