#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2010];
void solve()
{
	int n;
	cin>>n;
	vector<pair<string,string>>a;
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		a.push_back({s,t});	
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++) dp[i]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i].first>=a[j].second) dp[i]=max(dp[j]+1,dp[i]);
		}
	}
	cout<<dp[n-1]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
