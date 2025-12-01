#include <bits/stdc++.h>
using namespace std;
int dp[1010],x,y,n,m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		for(int i=n;i>=x;i--) dp[i]=max(dp[i],dp[i-x]+y);
	}
	for(int i=n;i>=1;i--)
	if(dp[n])
	{
		cout<<n;
		return 0;
	}
}
