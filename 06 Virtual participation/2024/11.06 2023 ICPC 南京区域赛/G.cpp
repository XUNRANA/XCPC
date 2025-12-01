#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,W,k,w,v;
int g[5010];
int dp[10010];
void solve()
{
	cin>>n>>W>>k;
	vector<pair<int,int>>a;
	a.push_back({0,0});
	for(int i=1;i<=n;i++) 
	{
		cin>>w>>v;
		a.push_back({w,v});
	}
	sort(a.begin(),a.end());
	
	priority_queue<int,vector<int>,greater<int> >q;
	int ss=0;
	g[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		q.push(a[i].second);
		ss+=a[i].second;
		if(q.size()>k)
		{
			ss-=q.top();
			q.pop();
		}
		g[i]=ss;
	}
	for(int i=0;i<=W;i++) dp[i]=0;
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=W;j>=a[i].first;j--)
		dp[j]=max(dp[j-a[i].first]+a[i].second,dp[j]);
		
		ans=max(dp[W]+g[i+1],ans);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
