#include <bits/stdc++.h>
using namespace std;
#define int long long
int y,n,m,dp[5000010],b[11];
void solve()
{
	cin>>y>>n>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(b+1,b+1+m);
	for(int i=1;i<=y;i++) dp[i]=1e18;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	for(int i=1;i<=n;i++) 
	{
		q.push({1,i});
		dp[i]=1;
		for(int j=1;j<=m;j++) 
		{
			if(i*b[j]>y) break;
			dp[i*b[j]]=min(dp[i*b[j]],dp[i]+1);
		}
	}
	
	for(int i=n+1;i<=y;i++)
	{
		while(i-q.top().second>n) q.pop();
		dp[i]=min(q.top().first+1,dp[i]);	
		q.push({dp[i],i});
		for(int j=1;j<=m;j++) 
		{
			if(i*b[j]>y) break;
			dp[i*b[j]]=min(dp[i*b[j]],dp[i]+1);
		}
	}
	cout<<dp[y]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
