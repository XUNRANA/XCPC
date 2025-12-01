#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,l,ans,t[200010];
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++) cin>>t[i];
	l=0;
	vector<int>d;
	for(int i=1;i<=q;i++) 
	{
		if(t[i]-l-1) d.push_back(t[i]-l-1);
		l=t[i];
	}
	if(n+1-l-1) d.push_back(n+1-l-1);
	vector<int>dp(n+1);
	for(int i=1;i<=m;i++)
	{
		int k,s;
		cin>>k>>s;
		for(int i=1;i<=n;i++)
		{
			if(i>=(1<<k)) dp[i]=max(dp[i],dp[i-(1<<k)]+s);
		}
	}
	for(auto i:d) ans+=dp[i];
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
