#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
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
 
int inv(int x)
{
	return ksm(x,P-2);
}

void solve()
{
	int n,m,p=1,f=0,ans=1,res=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++)//层数 
	{
		p=p*26%P;
		
		if(p>=n) f=1;//记录p大于n的状态，之和取模p会变小 
		if(!f) res=(res+min(p,n))%P;//每一层最多p个，最多n条链
		else res=(res+n)%P; 
		
		ans+=p*(1-ksm((1-inv(ksm(26,i))+P)%P,n)+P)%P;
		ans=(ans+P)%P;
		//第i层
		//某个点  被取到的概率是1/(26^i)
		//某个点  取不到的概率是1-1/(26^i)
		//某个点  n条链都取不到的概率是ksm(1-1/(26^i),n)
		//某个点  能被取到的概率是1-ksm(1-1/(26^i),n)
		//这一次期望取到的点数   sum(这一层的节点数)*(1-ksm(1-1/(26^i),n))  

	}
	cout<<res<<" "<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
