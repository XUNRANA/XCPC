#include <bits/stdc++.h>
using namespace std;
int n,x[5010],y[5010];
double dp[5010];
double dis(int i,int j)
{
	return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i]=max(dp[i],dp[j-1]+dis(j,i));
		}
	}
	printf("%.20f\n",dp[n]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
