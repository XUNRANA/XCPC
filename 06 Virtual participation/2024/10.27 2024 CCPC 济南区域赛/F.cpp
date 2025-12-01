#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int dp[100010][31];
int jc[100010];
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
	if(a<0||b<0) return 0;
	if(a<b) return 0;
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%P;
	
	for(int i=1;i<=100000;i++)
	{
		dp[i][1]=1;
		for(int j=i+i;j<=100000;j+=i)
		{
			for(int k=1;k<30;k++)
			{
				dp[j][k+1]=(dp[j][k+1]+dp[i][k])%P;
			}
		}
	}
	
}
void solve()
{
	int m,n;
	cin>>m>>n;
	int ans=C(m,n)*n%P;
	for(int i=1;i<=m;i++) for(int j=1;j<=30;j++) ans=(ans-dp[i][j]*C(m/i-1,n-j)%P+P)%P;
	cout<<ans<<"\n";
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
