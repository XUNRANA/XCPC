#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define P 1000000007
int n,t,ans,dp[N][10];
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
void solve()
{
 	cin>>n;
 	dp[0][1]=1;
 	for(int i=1;i<=n;i++)
 	{	
 		cin>>t;
 		t%=10;
 		for(int j=0;j<10;j++) dp[i][j]=dp[i-1][j];
 		for(int j=0;j<10;j++) dp[i][j*t%10]=(dp[i][j*t%10]+dp[i-1][j])%P;
 		for(int j=0;j<10;j++) if(j*t%10==6) ans=(ans+dp[i-1][j]*ksm(2,n-i))%P;
 	}
 	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

