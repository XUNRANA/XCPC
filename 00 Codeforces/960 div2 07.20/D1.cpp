#include <bits/stdc++.h>
using namespace std;
int n,a[200010],dp[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+(a[i]>0);
	
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
