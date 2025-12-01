#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	map<int,int>mp[2];
	for(int i=1;i<=n;i++)
	{
		int x;
		string s;
		cin>>x>>s;
		if(s=="F") mp[0][x]++;
		else mp[1][x]++;
	}
	int ans=0;
	for(auto i:mp[0])
	{
		if(mp[1].count(i.first)) ans+=min(mp[1][i.first],i.second);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
