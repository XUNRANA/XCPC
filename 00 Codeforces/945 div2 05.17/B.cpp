#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
bool ck(int x)
{
	vector<int>dp(20);
	for(int i=1;i<=x;i++)
	{
		for(int j=19;j>=0;j--)
		{
			if(a[i]>>j&1) dp[j]++;
		}
	}
	
	
	for(int i=x+1;i<=n;i++)
	{
		vector<int>dp1(20);
		for(int j=19;j>=0;j--)
		{
			if(a[i]>>j&1) dp1[j]++;
		}
		for(int j=19;j>=0;j--)
		{
			if(a[i-x]>>j&1) dp1[j]--;
		}
		for(int j=19;j>=0;j--)
		{
			if(dp[j]>0&&dp[j]+dp1[j]==0) return 0;
			if(dp[j]==0&&(dp[j]+dp1[j])>0) return 0;
			dp[j]+=dp1[j];
		}
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
