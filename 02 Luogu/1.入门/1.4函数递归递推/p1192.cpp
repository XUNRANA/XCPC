#include <bits/stdc++.h>
using namespace std;
#define m 100003
long long n,k,dp[100010];
int main()
{
	cin>>n>>k;
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=max(i-k,0ll);j--)
		dp[i]+=dp[j]%m;
		dp[i]%=m;
	}
	cout<<dp[n];
}

/*
#include <bits/stdc++.h>
using namespace std;
#define mod 100003
long long n,k,dp[1000000];
int main()
{
	dp[0]=dp[1]=1;
	cin>>n>>k;
	for(int i=2;i<=n;i++) for(int j=1;j<=k;j++)
	if(i>=j) dp[i]=(dp[i]+dp[i-j])%mod; 
	cout<<(dp[n]+mod)%mod;
}
*/
