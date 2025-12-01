#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int n,ans;
void dfs(int cnt,int prev)
{
	if(cnt==n) 
	{
		ans++;
		return ; 
	}
	for(auto &i:mp)//&!!!!!!!!!!!!!!!!
	{
		if(i.first!=prev&&i.second)
		{
			i.second--;
			dfs(cnt+1,i.first);
			i.second++;
		}
	}
}
void solve()
{
	string s;
	cin>>s; 
	n=s.size();
	for(auto i:s) mp[i-'a']++;
	dfs(0,-1);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
