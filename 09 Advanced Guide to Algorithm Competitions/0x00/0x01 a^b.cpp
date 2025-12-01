//求a^b%p 1<=a,b,p<=1e9
#include <bits/stdc++.h>
int power(int a,int b,int p)  //快速幂 时间复杂度O(log2 b)
{              
	int ans=1%p;   
	for(;b;b>>=1)// >>= 表示b右移一位 最高位填0 并赋值给b    ==  b/=2
	{    //b&1检查b的最低位是否为1,是否为奇数 
		if(b&1) ans=(long long)ans*a%p;
		a=(long long)a*a%p;
	}
	return ans;
}
using namespace std;
int main()
{
	int a,b,p;
	cin>>a>>b>>p;
	cout<<power(a,b,p);
}
