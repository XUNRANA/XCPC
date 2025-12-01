#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	map<string,set<string>>mp;
	for(int i=1;i<=n;i++)
	{
		string t,s,st;
		cin>>t>>s>>st;
		if(st=="accepted") mp[s].insert(t);
	}
	int ans=0;
	for(auto i:mp) ans=max(ans,(int)i.second.size());
	for(auto i:mp)
	{
		if(i.second.size()==ans)
		{
			cout<<i.first<<"\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
