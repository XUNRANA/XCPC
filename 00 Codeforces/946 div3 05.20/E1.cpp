#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,x,s,c,h;
void solve()
{
	cin>>m>>x;
	s=0;
	vector<int>dp(1,-1);
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>c>>h;
		s+=h;
		dp.resize(s+1,-1);//扩容，扩容的部分值为-1 
		for(int j=s;j>=h;j--)
		if(dp[j-h]>=c) dp[j]=max(dp[j],dp[j-h]-c);
		for(int j=0;j<=s;j++) if(dp[j]>=0) dp[j]+=x;
	}
	for(int i=s;i>=0;i--) 
	if(dp[i]>=0)
	{
		cout<<i<<"\n";
		return ;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
