#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int dp[1000010][2];
int f[1000010];
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
	int k,n;
	cin>>n>>k;
	dp[1][1]=5;//合法&最后一个为元音
	dp[1][0]=21;//合法&最后一个为辅音
	f[1]=dp[1][0]*ksm(5,n)%P;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])*21%P;
		if(i<=k) dp[i][1]=(dp[i-1][0]+dp[i-1][1])*5%P;
		else dp[i][1]=(f[i-1]-f[i-k-1]+P)%P*inv(ksm(5,n-i+1))%P;
		f[i]=(f[i-1]+dp[i][0]*ksm(5,n-i+1)%P)%P;
	}
	cout<<(dp[n][0]+dp[n][1])%P;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}