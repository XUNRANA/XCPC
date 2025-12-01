#include <bits/stdc++.h>
using namespace std;
int n,a[100010],dp[512];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=0;j<512;j++) dp[j]=1e9;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<512;j++)
		{
			if(dp[j]<a[i]) dp[j^a[i]]=min(dp[j^a[i]],a[i]);
		}
	}
	vector<int>ans;
	for(int i=0;i<512;i++) if(dp[i]!=1e9) ans.push_back(i);
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

