#include <bits/stdc++.h>
using namespace std;
bool cmp(array<int,2>a,array<int,2>b)
{
	return min(a[0],a[1])<min(b[0],b[1]);
}
int dp[200010][4];
void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i][0];
	for(int i=1;i<=n;i++) cin>>a[i][1];
	sort(a.begin()+1,a.end(),cmp);
	//1表示合法  0表示非法
	dp[1][0]=1;//偶数次翻转对i排序，i不翻转
	dp[1][1]=0;//偶数次翻转对i排序，i翻转
	
	dp[1][2]=0;//奇数次翻转对i排序，i不翻转
	dp[1][3]=1;//奇数次翻转对i排序，i翻转

	for(int i=2;i<=n;i++)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0;
		if(a[i-1][0]<a[i][0]&&a[i-1][1]<a[i][1])
		{
			dp[i][0]|=dp[i-1][0];
			dp[i][1]|=dp[i-1][1];
			dp[i][2]|=dp[i-1][3];
			dp[i][3]|=dp[i-1][2];
		}
		if(a[i-1][0]<a[i][1]&&a[i-1][1]<a[i][0])
		{
			dp[i][0]|=dp[i-1][2];
			dp[i][1]|=dp[i-1][3];
			dp[i][2]|=dp[i-1][1];
			dp[i][3]|=dp[i-1][0];
		}
	}
	cout<<((dp[n][0]|dp[n][2])?"YES\n":"NO\n");
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
