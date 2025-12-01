#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int dp[200010];
int f(int x)
{
	int s=0;
	while(x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
void solve()
{
	cin>>n;
	cout<<dp[n]<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=1,ans=0;i<=200000;i++)
	{
		ans+=f(i);
		dp[i]=ans;
	}
	int t;
	cin>>t;
	while(t--) solve();
}
