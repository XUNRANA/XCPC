#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,res,a[200010],dp[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],dp[i]=0;
	
	for(int i=2;i<=n;i++)
	{
		if(a[i]==1&&a[i]<a[i-1])
		{
			cout<<"-1\n";
			return ;
		}
	
		if(a[i]<a[i-1])
		{
			dp[i]=dp[i-1];
			int t=a[i];
			while(t<a[i-1])
			{
				dp[i]++;
				t*=t;
			}
		}
		else
		{
			if(a[i-1]==1) continue;
			int t=a[i-1],c=0;
			while(t*t<=a[i])
			{
				t*=t;
				c++;
			}
			dp[i]=max(0ll,dp[i-1]-c);
		}
	}
	
	res=0;
	for(int i=1;i<=n;i++) res+=dp[i];
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
