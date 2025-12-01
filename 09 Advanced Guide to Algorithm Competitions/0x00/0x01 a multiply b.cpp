//求a*b%p  1<=a,b,p<=1e18 
#include <bits/stdc++.h>
using namespace std;
long long mul(long long a,long long b,long long p) //快速乘 时间复杂度O(log2 b)
{
    long long ans=0;
    for(;b;b>>=1)  // 不断右移 b，每次迭代处理 b 的最低位
    {   //检查 b 的最低位是否为 1
        if(b&1) ans=(ans+a)%p;//如果最低位为 1，将 ans 与 a 相加，并对模数 p 取余  
        a=(a<<1)%p;           //将 a 左移一位(相当于乘以 2 )并对模数 p 取余
    }
    /*
    5 7 11
    b(最低位为1才进行加法运算) b/=2        a 
    7 (0 + 5) % 11 = 5               5%11  5
    3 (5 + 10) % 11 = 4              10%11 10
    1 (4 + 9) % 11 = 2               20%11 9
    */
    return ans; // 返回计算结果
}
long long mul1(long long a,long long b,long long p)
{//a*b%p == a*b-[a*b/p]*p    5(2) 7(1) 3
	a%=p;
	b%=p;
	long long c=(long double)a*b*1.0/p;
	long long ans=a*b-c*p;
	ans=(ans+p)%p;
	return ans;
}
int main()
{
	long long a,b,p;
	cin>>a>>b>>p;
	cout<<mul1(a,b,p);
}
