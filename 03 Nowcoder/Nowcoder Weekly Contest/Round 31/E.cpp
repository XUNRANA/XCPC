#include <bits/stdc++.h>
using namespace std;
int n,t,k;
void solve()
{
	cin>>n;
	vector<int>dp(80001,1e9);
	dp[40000]=0;
	for(int i=1;i<=n;i++,k^=1) 
	{
		cin>>t;
		vector<int>dpt(80001,1e9);
		for(int j=80000;j>=0;j--)
		{
			if(j-t>=0) dpt[j]=min(dpt[j],dp[j-t]);
			
			if(j+t>=0) dpt[j]=min(dpt[j],dp[j+t]+1);
		}
		dp=dpt;
	}
	if(dp[40000]==1e9) dp[40000]=-1;
	cout<<dp[40000];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

