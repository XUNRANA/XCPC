#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353 
int n,ans,lcm,sum,f[10000001],inv[10000001]; 
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
vector<int>pr;
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) 
	{
		inv[i]=1ll*(P-P/i)*inv[P%i]%P;//线性求逆元 
		if(!f[i]) 
		{
			pr.push_back(i);
			for(int j=i+i;j<=n;j+=i) f[j]=1;
		}
	}
}
signed main()
{
	cin>>n;
	if(n==1) ans=0;
	else if(n==2) ans=1;
	else if(n==3) ans=8;
	else
	{
		ans=0;
		lcm=1;
		init(n);
		for(auto i:pr) lcm=lcm*ksm(i,log(n)/log(i))%P;
		for(int i=1;i<=n;i++) 
		{
			//答案为正的圈数+负的圈数 
			int v=lcm*inv[i]%P;//第i个人的圈数 
			ans=(ans+v*(-i+1)%P+v*(n-i)%P+P)%P;
		}
	}
	cout<<ans<<"\n";
}
