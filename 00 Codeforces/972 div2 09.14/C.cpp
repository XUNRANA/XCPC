#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<string>s(n);
	for(int i=0;i<n;i++) cin>>s[i];
	array<int,5>dp;
	dp.fill(-1e9);
	dp[0]=0;
	string t="narek\n";
	for(int i=0;i<n;i++)
	{
		auto ndp=dp;
		for(int x=0;x<5;x++)
		{
			int y=x;
			int res=dp[x];
			for(auto c:s[i])
			{
				if(c==t[y]) 
				{
					y++;
					if(y==5)
					{
						y=0;
						res+=5;
					}
				}
				else if(t.find(c)!=-1) res--;
			}
			ndp[y]=max(ndp[y],res);
		}
		dp=ndp;
	}
	int ans=0;
	for(int i=0;i<5;i++) ans=max(ans,dp[i]-i);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
