#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
map<int,int>dp;
void init()
{
	for(int i=-5;i<=5;i++)
	{
		if(i==0) continue;
		for(int j=-5;j<=5;j++)
		{
			if(j==0) continue;
			dp[i+j]++;
		}
	}
	for(int i=-10;i<=10;i++) 
	{
		if(i==0) continue;
		dp[i]++;
	}
//	for(auto i:dp) cout<<i.first<<" "<<i.second<<"\n";
	
}
map<int,int>ans,ans1;
void solve()
{
	init();
	int x,y;
	cin>>x>>y;
	ans=dp;
	int s=0;
	while(y--)
	{
		ans1.clear();
		for(auto j:ans)
		{
			for(auto k:dp)
			{
				int a=j.first;
				int ca=j.second;
				int b=k.first;
				int cb=k.second;
				ans1[a+b]=(ans1[a+b]+ca*cb%P)%P;
			}
		}
		ans=ans1;
	}
	cout<<ans[x]<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
