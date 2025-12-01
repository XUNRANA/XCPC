#include <bits/stdc++.h>
using namespace std;
#define int long long
vector< pair<int,int> >g[20];
int n,a[20];
int dp[600000];
int count(int x)
{
	int res=0;
	for(int i=18;i>=0;i--)
	{
		if(x>>i&1) res++;
	}
	return res;
}
void init()
{
	g[1].push_back({0,2});
	g[17].push_back({16,18});
	g[3].push_back({0,7});
	g[6].push_back({2,11});
	g[12].push_back({7,16});
	g[15].push_back({18,11});
	
	g[4].push_back({0,9});
	g[4].push_back({1,8});
	g[4].push_back({3,5});
	
	g[5].push_back({2,9});
	g[5].push_back({4,6});
	g[5].push_back({1,10});
	
	
	g[10].push_back({6,14});
	g[10].push_back({5,15});
	g[10].push_back({9,11});
	
	g[14].push_back({9,18});
	g[14].push_back({10,17});
	g[14].push_back({13,15});
	
	g[13].push_back({9,16});
	g[13].push_back({8,17});
	g[13].push_back({12,14});
	
	g[8].push_back({7,9});
	g[8].push_back({12,4});
	g[8].push_back({3,13});
	
	
	g[9].push_back({5,13});
	g[9].push_back({10,8});
	g[9].push_back({14,4});


	map<int,vector<int>>mp;
	for(int i=1;i<(1<<19);i++) mp[count(i)].push_back(i);
	
	
	for(auto x:mp)
	{
		for(auto i:x.second)
		{		
			for(int j=0;j<=18;j++)
			{
				if(i>>j&1)
				{
					dp[i]=max(dp[i],dp[i^(1<<j)]);	
					for(auto k:g[j])
					{
						int s=k.first;
						int e=k.second;
						if(i>>s&1)
						{
							int t=i;
							t^=(1<<j);
							t^=(1<<s);
							t|=(1<<e);
							dp[i]=max(dp[i],dp[t]+a[j]);
						}
						
						if(i>>e&1)
						{
							int t=i;
							t^=(1<<j);
							t^=(1<<e);
							t|=(1<<s);
							dp[i]=max(dp[i],dp[t]+a[j]);
						}
					}
				}
			}
		}
	}
}
void solve()
{
	for(int i=0;i<=18;i++) cin>>a[i];
	init();
	cin>>n;
	while(n--)
	{
		string s;
		for(int i=1;i<=5;i++)
		{
			string t;
			cin>>t;
			s+=t;
		}
		int sta=0;
		for(int i=0;i<=18;i++)
		{
			if(s[i]=='#') sta+=1<<i;
		}
		cout<<dp[sta]<<"\n";
	}
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
