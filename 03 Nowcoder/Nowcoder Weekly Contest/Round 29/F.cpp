#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 1000000007
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
int dp[1010][1010];
void solve()
{
	int n,x,c1=0,c2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==1) c1++;
		else c2++;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)//dpij表示前i个有j个2时，先手获胜的概率
		{
			if(!j) dp[i][j]=1;
			else dp[i][j]=((i-j)*inv(i)%P*(1-dp[i-1][j]+P)%P+j*inv(i)%P*(1-dp[i][j-1]+P)%P)%P;
		}
	}
	cout<<dp[c2+c1][c2]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

