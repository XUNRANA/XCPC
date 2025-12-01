#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[810];
void init()
{
	jc[0]=1;
	for(int i=1;i<810;i++) jc[i]=jc[i-1]*i%P;
}
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
	return jc[a]*inv(jc[b]*jc[a-b]%P)%P;
}
int n,m,k,ans;
int dp[401][401][802];
char a[410][410];
void solve()
{
	init();
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],dp[i][j][0]=C(i-1+j-1,i-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)
			{
				if(a[i][j]=='A')
				{
					dp[i][j][1]=1;
				}
			}
			else if(i==1)
			{
				if(a[i][j]=='A')
				{
					for(int l=1;l<=k;l++)
					{
						dp[i][j][l]+=dp[i][j-1][l-1];
						dp[i][j][l]%=P;
					}
				}
			}
			else if(j==1)
			{
				if(a[i][j]=='A')
				{
					for(int l=1;l<=k;l++)
					{
						dp[i][j][l]+=dp[i-1][j][l-1];
						dp[i][j][l]%=P;
					}
				}
			}
			else
			{
				if(a[i][j]=='A')
				{
					for(int l=1;l<=k;l++)
					{
						dp[i][j][l]+=dp[i-1][j][l-1];
						dp[i][j][l]%=P;
						dp[i][j][l]+=dp[i][j-1][l-1];
						dp[i][j][l]%=P;
					}
				}
			}
			ans=(ans+dp[i][j][k]*C(n-i+m-j,n-i)%P)%P;
		}
	}
	cout<<ans*inv(C(n+m-2,n-1))%P<<"\n";		
}
/*
2 3 2
AAA
BBA
*/

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
