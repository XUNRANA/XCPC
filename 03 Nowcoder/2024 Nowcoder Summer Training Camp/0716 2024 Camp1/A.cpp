#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,m,p,ans;
int c[5010][5010];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void solve()
{
	cin>>n>>m>>p;
	for(int i=1;i<=5000;i++) c[i][0]=1;
	c[1][1]=1;
	for(int i=2;i<=5000;i++)
	{
		for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	for(int k=1;k<=n;k++)
	{//     枚举奇数位置   所有奇数一位&为1 m-1位    偶数每一位任意 m-1位
		ans+=c[n][k]*ksm((ksm(2,k)-1+p)%p,m-1)%p*ksm(ksm(2,n-k),m-1)%p;
		ans%=p;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve(); 
}
