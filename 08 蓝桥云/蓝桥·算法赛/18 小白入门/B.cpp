#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	vector<int>dp(b+1);
  	dp[a]=0;
	for(int i=a+1;i<=b;i++)
	if(i%c==0) dp[i]=1e9;
	else dp[i]=min(dp[i-1],dp[i-2])+1;
	
	cout<<dp[b]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
