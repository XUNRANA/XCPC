#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,m,s,q,t,p[100010],dp[100010];
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
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>p[i],s+=p[i];
	q=inv(s-p[1]); 
	for(int i=m-1;i>=1;i--)
	{
		t=s;
		for(int j=2;j<=n&&j*i<m;j++)
		t=(t+p[j]*dp[i*j])%P;
		dp[i]=t*q%P;
	}
	cout<<dp[1]<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 

