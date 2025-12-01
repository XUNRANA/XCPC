#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int dp[100010][4];
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1][0]=0;
	dp[1][1]=1;//变成1 
	dp[1][2]=1;//变成偶数 
	dp[1][3]=1;//变成奇数 
	for(int i=2;i<=n;i++) 
	{
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=1e9;
		//0 0
		if(is(a[i-1]+a[i])) dp[i][0]=min(dp[i][0],dp[i-1][0]); 
		
		//1 0
		if(is(1+a[i])) dp[i][0]=min(dp[i][0],dp[i-1][1]); 
		
		//2 0
		if(a[i]%2==1) dp[i][0]=min(dp[i][0],dp[i-1][2]); 
		
		//3 0
		if(a[i]%2==0) dp[i][0]=min(dp[i][0],dp[i-1][3]); 
		
		//0 1
		if(is(a[i-1]+1)) dp[i][1]=min(dp[i][1],dp[i-1][0]+1); 
		//1 1
		dp[i][1]=min(dp[i][1],dp[i-1][1]+1); 
		//2 1  
		dp[i][1]=min(dp[i][1],dp[i-1][2]+1);
		//3 1  no
		
		//0 2
		if(a[i-1]%2==1) dp[i][2]=min(dp[i][2],dp[i-1][0]+1);
		//1 2
		dp[i][2]=min(dp[i][2],dp[i-1][1]+1);
		//2 2
		
		//3 2
		dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
		
		
		//0 3
		if(a[i-1]%2==0) dp[i][3]=min(dp[i][3],dp[i-1][0]+1);
		//1 3 no
		
		//2 3
		dp[i][3]=min(dp[i][3],dp[i-1][2]+1);
		//3 3
	}
	cout<<min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]})<<"\n";	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
