#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,a[200010],dp[200010];
void solve()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	sort(a+1,a+1+m);
	if(n>t) cout<<"0\n";
	else if(n==t) cout<<n<<"\n";
	else 
	{
		for(int i=n;i<=t;i++) dp[i]=n;
		set<int>s;
		for(int i=2;i<=m;i++) s.insert(2*(a[i]-a[i-1]));
		for(int j=n;j<=t;j++) 
        for(auto i:s)
        if(j-i>=n) dp[j]=max(dp[j],dp[j-i]+i);
        else break;
        cout<<dp[t]<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
