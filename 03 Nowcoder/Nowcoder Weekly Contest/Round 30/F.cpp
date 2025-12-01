#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long 
int n,m,t,c1[3],c2[3];
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
int dp[60][60];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		c1[t]++;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		c2[t]++;
	}
	if(!c1[2]&&!c2[2])
	{
		cout<<"0\n";
		return ;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=1;
			int p12=(i*inv(i+c1[2])%P)*(c2[2]*inv(j+c2[2])%P)%P;
			int p21=(c1[2]*inv(i+c1[2])%P)*(j*inv(j+c2[2])%P)%P;
			if(i) dp[i][j]+=p12*dp[i-1][j]%P;
			if(j) dp[i][j]+=p21*dp[i][j-1]%P;
			dp[i][j]=dp[i][j]%P*inv((p12+p21)%P)%P;
		}
	}
	cout<<dp[c1[1]][c2[1]]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

