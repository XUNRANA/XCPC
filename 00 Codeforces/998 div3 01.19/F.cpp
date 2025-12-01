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
int C(int a,int b)
{
	if(b>a||b<0) return 0;
	int res=1;
	for(int i=1;i<=b;i++) res=res*(a-i+1)%P;
	for(int i=1;i<=b;i++) res=res*inv(i)%P;
	return res;
}
int dp[100010][21];
void solve()
{
	int k,n;
	cin>>k>>n;
	for(int i=2;i<=k;i++) for(int j=1;j<19;j++) dp[i][j]=0; 
	for(int i=2;i<=k;i++)
	{
		dp[i][1]=1;//1个数乘积为i
		for(int j=1;j<19;j++)
		{
			for(int d=2;d*i<=k;d++)
			{
				//j个数乘积为i---->j+1个数乘积为i*d
				dp[i*d][j+1]+=dp[i][j];
				dp[i*d][j+1]%=P;
			}
		}
	}
	cout<<n<<" ";
	for(int i=2;i<=k;i++)
	{
		int res=0;
		for(int j=1;j<20;j++)
		{
			//上指标求和:C(j,j)+C(j+1,j)+..C(n,j)==c(n+1,j+1)
			res+=dp[i][j]*C(n+1,j+1)%P;
			res%=P;
		}
		cout<<res<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
