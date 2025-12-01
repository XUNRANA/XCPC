#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int,vector<int>>mx,my;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			mx[x].push_back(i);
			my[x].push_back(j);
		}
	}
	int ans=0;
	for(auto i:mx)
	{
		sort(i.second.begin(),i.second.end());
		int cnt=0;
		int sum=0;
		for(auto j:i.second)
		{
			ans+=cnt*j-sum;
			sum+=j;
			cnt++;
		}
	}
	for(auto i:my)
	{
		sort(i.second.begin(),i.second.end());
		int cnt=0;
		int sum=0;
		for(auto j:i.second)
		{
			ans+=cnt*j-sum;
			sum+=j;
			cnt++;
		}
	}
	cout<<2*ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
