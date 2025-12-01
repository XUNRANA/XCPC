#include <bits/stdc++.h>
using namespace std;//别碰数学 
#define int long long
int ck(int x)// 欧拉函数，用于计算一个整数的欧拉函数值
{
	int res=x;// 初始结果为 x
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)// 如果 i 是 x 的因数
		{
			res=res/i*(i-1);// 使用欧拉函数公式
			while(x%i==0) x/=i;// 去掉所有 i 的倍数
		}
	}
	if(x>1) res=res/x*(x-1);
	return res;
}
int ksm(__int128 a,int b,int P)
{
	__int128 res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
void solve()
{
	int p,q,c2=0,c5=0;
	cin>>p>>q;
	q/=__gcd(p,q);// 将 q 化简为最简分母，去掉与 p 的最大公约数部分
	while(q%2==0) q/=2,c2++;// 计算 q 中 2 的因数个数，并去掉所有的 2 因数
	while(q%5==0) q/=5,c5++;// 计算 q 中 5 的因数个数，并去掉所有的 5 因数
	if(q==1) cout<<"-1\n";// 如果此时 q 为 1，说明是有限小数，输出 -1
	else
	{
		int t=ck(q);// 计算剩余 q 的欧拉函数值
		int mi=1e16;// 初始化最小循环节长度为一个很大的数
		for(int i=1;i*i<=t;i++)// 遍历 t 的所有因数
		{
			if(t%i==0)
			{// 如果 10^i ≡ 1 (mod q)，更新最小循环节长度
				if(ksm(10,i,q)==1) mi=min(mi,i);
				if(ksm(10,t/i,q)==1) mi=min(mi,t/i);
			}
		}// 输出非循环部分长度和循环节长度
		cout<<max(c2,c5)<<" "<<mi<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
