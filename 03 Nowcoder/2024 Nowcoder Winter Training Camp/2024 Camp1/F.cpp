#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int jc[100010],n,m,ans;
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
int C(int a,int b)
{
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%P;
}
void solve()
{
	//第二类斯特拉数（不排列）： s(n,m)=求和(k:0-m) (-1^k)*C(m,k)*(m-k)^n*(1/m!) 
	cin>>n>>m;
	//s(n,m)
	ans=0;
	for(int k=0;k<=m;k++)
	{
		if(k&1) ans=(ans-C(m,k)*ksm(m-k,n)+P)%P;
		else ans=(ans+C(m,k)*ksm(m-k,n)+P)%P;
	} 
	cout<<ans*ksm(jc[m],P-2)%P<<"\n";
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
